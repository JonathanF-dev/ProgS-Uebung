
import Sqrtlib
import System.IO

-- Program entry point
main :: IO ()
main = putStr "Bitte geben Sie eine Zahl ein: " >>
  hFlush stdout >>
  getLine >>= 
  (\xStr -> 
    let x = read xStr :: Double
    in putStr ("Die Wurzel aus " ++ xStr ++ " ist: ") >> putStrLn (show $ Sqrtlib.sqrt_newton' x))