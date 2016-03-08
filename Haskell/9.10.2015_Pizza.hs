{-#LANGUAGE GADTs, InstanceSigs, KindSignatures#-}

data Topping = Ham | Pinapple | Tuna

--deriving Show

--Show::(show a)=> a -> String
instance Show Topping where
    show::Topping -> String
    show Ham = "ham"
    show Pinapple = "pinapple"
    show Tuna = "tuna"
