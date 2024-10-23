import System.IO

fac n = fac' n 1
  where fac' x r | x == 0 = r
                 | otherwise = fac' (x-1) (r*x)

main = putStr "Bitte geben Sie eine Zahl ein: " >>
  hFlush stdout >>
  getLine >>=
  (\xStr ->
    let x = read xStr :: Int
    in putStr ("Die Fakultät von " ++ xStr ++ " ist: ") >> putStrLn (show $ fac x))
