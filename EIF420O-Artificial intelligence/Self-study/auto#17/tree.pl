height(leaf(_), 0).

height(bintree{data:_, left:Left, right:Right}, Height) :-
  height(Left, LeftHeight),
	HeightL is LeftHeight + 1,
	height(Right, RightHeight),
	HeightR is RightHeight + 1,
	Height is max(HeightL, HeightR).
	