
insert x [] = [x]
insert x (y:ys) | x < y = x:y:ys
                | otherwise = y:(insert x ys)

insertionSort [] = []
insertionSort (x:xs) = insert x (insertionSort xs)

main = putStrLn $ "Sorted: " ++ (show $ insertionSort [4,30,2,3,6,99,8,11,23])