%%%%%%%%%%%%%%%%%%%% UTILS %%%%%%%%%%%%%
zip(L, M, Z) :- maplist( [X, Y, [X, Y]] >> true, L, M, Z)
.
enumerate(L, EL) :-
    length(L, N),  numlist(1, N, LN), zip(LN, L, EL)
.
index_of(V, L, P) :- nth1(P, L, V).

new_id(B, I) :- gensym(B, I).

list_split(L, A, X, B) :-  append(A, [X | B], L).


list_set_value(L, I, V, LS) :-
   list_split(L, A, _, B),
   I1 is I - 1, I1 >= 0,
   length(A, I1),
   append(A, [V | B], LS)
.

list_at(L, I, V) :-
	nth1(I, L, V)
.
list_swap(L, I, J, LS):-
   list_at(L, I, VI), list_at(L, J, VJ),
   list_set_value(L, I, VJ, LJ),
   list_set_value(LJ, J, VI, LS)
   % ,writeln(['\t*** Lista empty ***', L]),
   % writeln(['\t*** Nueva Lista ***', LS])
.

column_swap(Column, NewRow, EmptyRow, [NewRowUpdated, EmptyRowUpdated]) :-
	% writeln(['\t*** Lista empty ***', EmptyRow, "*** Lista a intercambiar *** ",NewRow]),
    append(EmptyRow, NewRow, Concatenated),
    length(EmptyRow, L),
    SwapIndex is L + Column,
    list_swap(Concatenated, Column, SwapIndex, Swapped),
    length(EmptyRowUpdated, L),
    append(EmptyRowUpdated, NewRowUpdated, Swapped)
	% ,writeln(['\t*** Nueva Lista ***', NewRowUpdated])
.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- dynamic visited/1.
visited_clear :-
	retractall(visited(_))
.

set_visited(I) :-
    
	assert(visited(I))
.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

board_from(L, Id) :-
    board_new_id(Id),
    board_clear(Id),
    enumerate(L, EL),
    forall(member(R, EL), board_add(Id, R))
.

board_to(Id, L) :-
	findall([I, Row], board_row(Id, I, Row), L)
.

:- dynamic board_row/3.
:- dynamic board_empty/3.

board_new_id(I) :- new_id('board_', I).

board_clear_all :-
   retractall(board_row(_, _)),
   retractall(board_empty(_,_))
.
   
board_clear(Id) :-
   retractall(board_row(Id, _)),
   retractall(board_empty(Id,_))
.

board_clone(Id, IdC):-
   findall([RId, R], board_row(Id, RId, R), EL),
   board_new_id(IdC),
   forall(member(RC, EL), board_add(IdC, RC))
.

board_add(Id, [I, R]) :-
    assert(board_row(Id, I, R)),
    ( index_of(empty, R, J) -> board_add_empty(Id, I, J) ; true )
.
board_update(Id, I, RS) :-
    % writeln(['*** update ***', Id, I, RS]), 
    retract(board_row(Id, I, _)),
	board_add(Id, [I, RS])
.
board_add_empty(Id, I, J) :-
    retractall(board_empty(Id, _,_)),
    assert(board_empty(Id, I, J))
.

board_show(Id) :- 
   writeln('Board rows:'),
   findall([IR, Row], board_row(Id, IR, Row), LR),
   sort(LR, LRS),
   forall( member([I, R], LRS), writeln([I, R]) ),
   writeln('Empty at:'),
   board_empty(Id, EI, EJ),
   write([EI, EJ])
.

board_get_valid_move(Id, P, D) :-
    board_empty(Id, I, J),
    ( (I > 1, I1 is I - 1, P=[I1, J], D = up);
      (I < 3, I1 is I + 1, P=[I1, J], D = down);
      (J > 1, J1 is J - 1, P=[I, J1], D = left);
      (J < 3, J1 is J + 1, P=[I, J1], D = right))
.


board_apply_move(Id,D) :-
    board_get_valid_move(Id, [I, J1], D), 
    member(D, [left, right]),
	format('\t*** Board = ~w move = ~w~n', [Id, D]),
    board_row(Id, I, R),
    board_empty(Id, I, J),
    list_swap(R, J, J1, RS),
    board_update(Id, I, RS)
    % ,writeln(['\t*** ------------- ***'])
.
    

board_apply_move(Id, D) :-
	
    board_get_valid_move(Id, [I, _], D), 
	member(D, [up, down]), 
	format('\t*** Board = ~w move = ~w~n', [Id, D]),
    board_row(Id, I, NewRow),
    board_empty(Id, Row, Column),
    board_row(Id, Row, EmptyRow),
    column_swap(Column, NewRow, EmptyRow, [NewRowUpdated, EmptyRowUpdated]),
    board_update(Id, I, NewRowUpdated),
    board_update(Id, Row, EmptyRowUpdated)
	% ,writeln(['\t*** ------------- ***'])
.


board_child(Id, IdChild, D) :-
   member(D, [up, down, left, right]),
   board_clone(Id, IdChild), 
   board_apply_move(IdChild, D)
.

board_is_visited(I) :-
  board_to(I, L),
  term_hash(L, Hash),
  visited(Hash)
.

board_set_visited(I) :-
    board_to(I, L),
    term_hash(L, HI),
	assert(visited(HI)),
	format('~n Board = ~a Hash=~d~n', [I,HI])
.

board_start_play_dsf(Id) :-
	visited_clear,
    Depth = 4,
	D = root,
	board_play_dfs(Id, Depth, D)
.
board_play_dfs(Id, Depth, D) :-
   format('~n(1)Trying board ~a depth=~d move=~s~n', [Id, Depth, D]),
   Depth > 0, 
   \+ board_is_visited(Id),
   board_set_visited(Id),
   findall([IdChild, DChild], board_child(Id, IdChild, DChild), ChildList),
   Depth1 is Depth - 1,
   forall(member([IdC, DC], ChildList), board_play_dfs(IdC, Depth1, DC)),
   format('~n(1)Processed board ~a depth=~d move=~s~n', [Id, Depth, D])
.
board_play_dfs(Id, Depth, D):-
   format('~n(2)Trying board ~a depth=~d move=~s~n', [Id, Depth, D]),
   Depth = 0; 
   board_is_visited(Id),
   format('~n(2)Visited or depth exceding board ~a depth=~d move=~s~n', [Id, Depth, D])
.
   
test(Id) :-
  L = [
        [1,empty,3],
        [8,2,4],
        [7,6,5]],
   
  board_from(L, Id),
  board_show(Id)
.