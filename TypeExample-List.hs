{-# LANGUAGE GADTs, KindSignatures #-}

module Data2 where

data Wibble = Wibble Int

instance Show Wibble where
    show (Wibble n) = take n $ cycle "$"

data List :: * -> * where
    EndOfList :: List x
    Cons :: a -> List a -> List a
    --deriving Show

instance Show a => Show (List a) where
    show EndOfList = "."
    show (Cons x xs) = show x ++ "," ++ show xs

data List2 :: * -> * -> * where
    Cons2 :: a -> b -> List2 a b -> List2 a b
    EOL2 :: List2 a b