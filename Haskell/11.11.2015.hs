{-# LANGUAGE GADTs, KindSignatures #-}
import Data.IORef

factorial::Int->Int
factorial 0 = 1;
factorial x = x * factorial(x-1)

floop::Int->IO()
floop 0 = do
    putStrLn $ "Factorial 0 = " ++ show (factorial 0)
floop x = do
    floop(x-1)
    putStrLn $ "Factorial " ++ show x ++ " = " ++ show (factorial x)

main1 = loop1 0

loop1::Int->IO ()
loop1 n = do
    putStrLn $ "fac " ++ show n ++ " = " ++ show (factorial n)
    if n <= 10
        then loop1 (n+1)
        else return()

main2::IO ()
main2 = do
    r <- newIORef 10
    loop2 r

loop2::IORef Int -> IO()
loop2 x = do
    a <- readIORef x
    if (a < 0)
    then return ()
    else do
        if (a /= 0)
        then
            do
                writeIORef x (a - 1)
                loop2(x)
        else
            return ()
        putStrLn $ "Factorial " ++ show a ++ " = " ++ show (factorial a)

