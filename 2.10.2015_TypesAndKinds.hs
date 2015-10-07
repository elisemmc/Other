{-# LANGUAGE GADTs, KindSignatures #-}

module Data2 where

data Wibble = Wibble Int

instance Show Wibble where
    show (Wibble n) = take n $ cycle "$"

instance Num Wibble where
    (+) (Wibble a) (Wibble b) = Wibble (a + b)
    fromInteger = Wibble . fromInteger

data List :: * -> * where
    EndOfList :: List x
    Cons :: a -> List a -> List a
    --deriving Show

instance Show a => Show (List a) where
    show EndOfList = "."
    show (Cons x xs) = show x ++ "," ++ show xs

data List2 :: * -> * -> * where
    Cons2 :: a -> b -> List2 b a -> List2 a b
    EOL2 :: List2 a b

instance (Show a,Show b) => Show (List2 a b) where
    show EOL2 = "#"
    show (Cons2 a b xs) = show a ++ "!" ++ show b ++ "@" ++ show xs

add :: Maybe Int -> Maybe Int -> Maybe Int
add (Just a) (Just b) = Just (a + b)
add _        _        = Nothing

catch :: Maybe a -> Maybe a -> Maybe a
catch (Just a) _ = Just a
catch _        o = o

next :: Maybe a -> (a -> Maybe b) -> Maybe b
next Nothing _ = Nothing
next (Just a) k = k a
