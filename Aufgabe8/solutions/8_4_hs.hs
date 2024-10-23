import System.IO

fib 1 = 1
fib 2 = 1
fib x = (fib $ x-1) + (fib $ x-2)

fib2 n =
  let fib2' f1 f2 i = if i == n
                      then f1
                      else (fib2' f2 (f1 + f2) (i + 1))
  in fib2' 0 1 0

fib3 n = fib3' 0 1 0
  where fib3' f1 f2 i = if i == n then f1 else fib3' f2 (f1+f2) (i+1)


main :: IO ()
main = putStr "Bitte geben Sie eine Zahl ein: " >>
  hFlush stdout >>
  getLine >>=
  (\xStr ->
    let x = read xStr :: Int
    in putStr ("Die " ++ xStr ++ " Fibonacci Zahl lautet: ") >> putStrLn (show $ fib x))
