% Caso base: Una lista vacía está ordenada
is_sorted([]).

% Caso base: Una lista con un solo elemento está ordenada
is_sorted([_]).

% Regla recursiva: Una lista de dos o más elementos está ordenada si el primer elemento
% es menor o igual que el segundo y el resto de la lista también está ordenado
is_sorted([X, Y | Tail]) :-
    X =< Y,
    is_sorted([Y | Tail]).