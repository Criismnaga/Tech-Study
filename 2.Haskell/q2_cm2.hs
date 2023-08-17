elemNum :: Int-> [Int] -> Int  
elemNum x [] = 0
elemNum x (y:ys)
  | x == y = 1 + elemNum x ys
  | otherwise = elemNum x ys
 
  
      
