split_at(0,L,[],L) :- !.
  split_at(N,[H|T],[H|L1],L2) :-
  M is N -1,
  split_at(M,T,L1,L2).

list_set_value(Index, List, NewValue, NewList) :-
    split_at(Index, List, Prefix, [_|Suffix]),
    append(Prefix, [NewValue|Suffix], NewList).

example_set_value :-
    List = [1, 2, 3, 4, 5],
    list_set_value(2, List, 99, NewList),
    writeln(NewList).