import System.IO

insert x [] = [x]
insert x (y:ys) | x < y = x:y:ys 
                | otherwise =  y : insert x ys

insertion_sort [] = []
insertion_sort (x : xs) = insert x (insertion_sort xs)

main = putStrLn $ "Sorted: " ++ (show $ insertion_sort [4,30,2,3,6,99,8,11,23])
