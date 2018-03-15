mysum :: [Int] -> Int
mysum [] = 0
mysum (x:xs) = x + mysum xs

mysum' :: Num a => [a] -> a
mysum' [] = 0
mysum' (x:xs) = x + mysum' xs

second :: [a] -> [a]
second [] = []
second [x] = []
second (x:y:xs) = y : second xs

prop_second xs = length (second xs) <= length xs 

minGroundV vspeed y = ceiling ( sqrt ( ( 2 * 3.711 * y ) + ( vspeed * vspeed ) ) )