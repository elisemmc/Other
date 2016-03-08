{-# LANGUAGE GADTs, KindSignatures #-}

data Expr :: * where
    Lit  :: Int -> Expr
    Add  :: Expr -> Expr -> Expr
    Mul  :: Expr -> Expr -> Expr
    VarX :: Expr
    deriving Show

eval :: Expr -> (Int -> Int)
eval (Lit i)     x = i
eval (Add e1 e2) x = eval e1 x + eval e2 x
eval (Mul e1 e2) x = eval e1 x * eval e2 x
eval VarX        x = x --error "find X yourself"

instance Num Expr where
    fromInteger = Lit . fromInteger
    (+) = Add
    (*) = Mul

x :: Expr
x = VarX

data A = A ( Int-> Int )

eval' :: Expr -> A
eval' (Lit i)      = A (\_x -> i)
{--
eval (Add e1 e2) x = eval e1 x + eval e2 x
eval (Mul e1 e2) x = eval e1 x * eval e2 x
--}
eval' VarX        x = A (\ x -> x) --error "find X yourself"

runA :: A -> Int -> Int
run A (A f) x = f x
lift2A :: ( Int -> Int -> Int ) -> A -> A -> A
lift2A f ( A f1 ) ( A f2 ) = A (\ x -> f1 x `f` f2 x )
