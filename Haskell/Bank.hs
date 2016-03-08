import Control.Concurrent
import Control.Concurrent.STM

import System.Random
import Data.IORef

main = do
        acc1 <- newTVarIO 1000
        acc2 <- newTVarIO 2000
        acc3 <- newTVarIO 0
        
        totals [acc1,acc2,acc3]
        parity [acc1,acc2,acc3]

        let loop = do
            atomically $ moveMoney 500 acc1 acc3
            atomically $ moveMoney 500 acc3 acc2
            atomically $ moveMoney 500 acc2 acc1
            loop

        forkIO $ loop

        let loop = do
                totals [acc1,acc2,acc3]
                parity [acc1,acc2,acc3]
                loop
                
        loop                

parity :: [TVar Int] -> IO ()
parity accs = do
    rs <- atomically $ mapM readTVar accs
    print ("parity",sum rs)
    if (sum rs) /= 3000 
    then error "parity error"
    else return ()

totals :: [TVar Int] -> IO ()
totals accs = sequence_ 
        [ readTVarIO acc >>= \ v -> print (i,v)
        | (acc,i) <- accs `zip` [1..]
        ]     

-- Move from first to second ref
moveMoney :: Int -> TVar Int -> TVar Int -> STM ()
moveMoney n a1 a2 = do
        v1 <- readTVar a1
        v2 <- readTVar a2
        writeTVar a1 (v1 - n)
        writeTVar a2 (v2 + n)

-- do not use for now
pause :: IO ()
pause = do
        n <- randomRIO (0,1000)
        putStrLn $ "pause for " ++ show n
        threadDelay (n * 1000)
        

