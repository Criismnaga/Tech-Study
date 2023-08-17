power :: Int -> Int -> Int
power x y
        | x <= 0 = -1
        | y <= 0 = 1
        | otherwise = x * power x (y-1)
