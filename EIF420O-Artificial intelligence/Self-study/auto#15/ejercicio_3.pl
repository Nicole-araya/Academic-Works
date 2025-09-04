% Hechos que representan los nodos del grafo
nodo(a).
nodo(b).
nodo(c).
nodo(d).
nodo(e).
nodo(f).

% Reglas que representan las conexiones entre nodos (aristas)
% Nota: Utilizaremos la notación de Prolog donde ',' representa AND.

% Conexiones desde el nodo 'a'
a :- b, d.

% Conexiones desde el nodo 'b'
b :- c, f.

% Conexiones desde el nodo 'c'
c :- e.

% Conexiones desde el nodo 'f'
f :- d.