palinDromo::String->Bool
palinDromo palavra
  | palavra == inverso = True
  | otherwise = False
  where
    inverso = contrario palavra

contrario :: [Char] -> [Char]
contrario [] = []
contrario (x : xs) = contrario xs ++ [x]