import System.IO

-- Fundamental expressions for solving the problem
isGoodEnough x y = abs (y*y - x) < 0.0001
improve x y = 0.5*(y + x/y)

-- Solution 1
sqrt_newton x = head (filter (isGoodEnough x) (iterate (improve x) 1))

-- Solution 2
-- Note: this does not use the global iterate from the 
-- standard library!
sqrt_newton' x = iterate x 1
  where iterate x y | (isGoodEnough x y) = y
                    | otherwise = iterate x (improve x y)

-- Program entry point
main :: IO ()
main = putStr "Bitte geben Sie eine Zahl ein: " >>
  hFlush stdout >>
  getLine >>= 
  (\xStr -> 
    let x = read xStr :: Double
    in putStr ("Die Wurzel aus " ++ xStr ++ " ist: ") >> putStrLn (show $ sqrt_newton' x))