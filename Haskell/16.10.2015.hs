{-# LANGUAGE GADTs, KindSignatures,  #-}

import System.Random

--data Tree a = Node (Tree a) (Tree a) | Leaf a
{-
data Tree :: *->* where
    Node :: Tree a -> Tree a -> Tree a
    Leaf :: a                -> Tree a

sum :: (Num a) => Tree a -> a
    sum (Leaf a) = a
    sum (Node t1 t2) = sum t1 + sum t2
-}
data Rose a = Node [Rose a] | Leaf a deriving (Show)
{-
data Rose :: *->* where
    Node :: [Rose a] -> Rose a
    Leaf :: a        -> Rose a
    deriving (Show)
-}
sumRose :: Num a => Rose a -> a
sumRose (Leaf a)  = a
sumrose (Node xs) = sum (map sumRose xs)

data Tree :: *->* where
    Empty :: Tree a
    Node :: Tree a -> a -> Tree a -> Tree a
    deriving Show

tree g = if b then
         then Empty
         else Node (tree g1) r (tree g2)
    where
        (b::Bool, g') = random g
        (r, g'') = random g'
        (g1,g2)  = split g''