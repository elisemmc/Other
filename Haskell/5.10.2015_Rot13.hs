{-# LANGUAGE GADTs, KindSignatures #-}

module Rot13 where

import Prelude hiding (sum)
import Data.Char

data Rot :: * -> * where
    Symbol :: Char -> Rot a
    Thing :: a     -> Rot a
    deriving (Show)

instance Functor Rot where
    fmap f (Symbol s) = Symbol s
    fmap f (Thing t) = Thing (f t)


doRot13 :: Rot Int -> Rot Int
doRot13 = fmap (\ i -> (i + 13) `mod` 26)
--doRot13 (Symbol s) = Symbol s
--doRot13 (Char i)   = Char((i+13) 'mod' 26)


fromChar :: Char -> Rot Int
fromChar c
    | c >= 'a' && c <= 'z' = Thing (ord c - ord 'a')
    | otherwise            = Symbol c

toChar :: Rot Int -> Char
toChar (Symbol s) = s
toChar (Thing i)  = chr (ord 'a' +i)

rot13 :: String -> String
rot13 = map toChar . map doRot13 . map fromChar
--rot13 = map (toChar . doRot13 . fromChar)      -- same as above line
--rot13 = fmap toChar . fmap (fmap(\ i -> (i +13) `mod` 26)) . fmap fromChar
