{-#LANGUAGE GADTs, KindSignatures#-}

type Toppings = String
type Size = Int

data Pizza :: * where
    Pizza :: [Toppings] -> Size -> Pizza

    --deriving Show

instance Show Pizza where
    --show (Size a) = "Your pizza is a size"
    --show (Toppings b) = "Your pizza has toppings"
    show (Pizza a b) = "You have a " ++ (show b) ++ " pizza with " ++ (show a) 
