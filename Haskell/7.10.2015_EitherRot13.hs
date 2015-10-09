{-# LANGUAGE GADTs, KindSignatures #-}

module EitherRot13 where

import Prelude hiding (sum)
import Data.Char

fromChar :: Char -> Either Char Int
fromChar c
    | c >= 'a' && c <= 'z' = Right (ord c - ord 'a')
    | otherwise            = Left c

toChar :: Either Char Int -> Char
toChar (Left c) = c
toChar (Right i) = chr(ord 'a' + i)

rot13 :: String-> String
rot13 = fmap toChar
	  . fmap (fmap (\ i -> (i + 13) `mod` 26))
	  . fmap fromChar