{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use camelCase" #-}
import System.IO

persion = 0.000001
isGoodEnough x y = abs (x*x - y) < persion
improve x y = 0.5*(y + x/y)

newton_sqrt :: Double -> Double
newton_sqrt x = iterate x 1
  where iterate x y | isGoodEnough x y =  y
                    | otherwise = iterate x (improve x y )

main :: IO ()
main = putStr "Bitte geben Sie eine Zahl ein: " >>
  hFlush stdout >>
  getLine >>=
  (\xStr ->
    let x = read xStr :: Double
    in putStr ("Die Wurzel aus " ++ xStr ++ " ist: ") >> print (newton_sqrt x))
