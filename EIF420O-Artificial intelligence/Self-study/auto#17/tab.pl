zip(L, M, Z):- maplist( [X, Y , [X,Y]] >> true, L, M, Z ).

enumerate(L, EL):-
		length(L,N), numlist(1, N, LN), zip(LN, L, EL)
.

index_of(V, L, P) :- nth1(P, L, V).

new_id(B, I) :- gensym(B, I).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

board_from(L, Id) :-
	board_new_id(Id),
	board_clear(Id),
	enumerate(L, EL),
	forall(member(R, EL), board_add(Id,R))
.

board_new_id(I) :- new_id('board_',I).

:- dynamic board_row/3.
:- dynamic board_empty/3.

board_clear_all :-
	retractall(board_row(_,_,_)),
	retractall(board_empty(_,_,_))
.

board_clear(Id) :-
	retractall(board_row(Id,_,_)),
	retractall(board_empty(Id,_,_))
.

board_add(Id, [I, R]) :-
	assert(board_row(Id, I,R)),
	(index_of(empty, R, J) -> board_add_empty(Id, I, J) ; true)
.

board_add_empty(Id,I, J):-
	retractall(board_empty(Id,_,_)),
	assert(board_empty(Id,I,J))
.

board_show(Id) :-
	writeIn('Board rows: '),
	forall( board_row(Id,I,R), writeIn([I,R]) ),
	writeIn('Empty at: '),
	board_empty(Id,EI, EJ),
	writeIn([EI, EJ])
.

board_get_valid_move(Id,P, D) :-
	board_empty(Id,I, J),
	(	(I > 1, I1 is I - 1, P=[I1,J], D = up);
		(I < 3, I1 is I + 1, P=[I1,J], D = down);
		(J > 1, J1 is J - 1, P=[I, J1], D = left);
		(J < 3, J1 is J + 1, P=[I, J1], D = right) )
.

test :-
	L = [
		[1,3,empty],
		[8,2,4],
		[7,6,5]],
	board_from(Id,L),
	board_show(Id)
.