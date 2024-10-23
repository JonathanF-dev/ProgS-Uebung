
isOdd  x = (mod x 2) /= 0

unevenList a b = filter isOdd [a..b]

main = putStrLn $ show $ unevenList 1 10
