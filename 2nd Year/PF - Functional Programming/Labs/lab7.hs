data Fruct
  = Mar String Bool
  | Portocala String Int

ionatanFaraVierme = Mar "Ionatan" False
goldenCuVierme = Mar "Golden Delicious" True
portocalaSicilia10 = Portocala "Sanguinello" 10
listaFructe = [Mar "Ionatan" False,
                Portocala "Sanguinello" 10,
                Portocala "Valencia" 22,
                Mar "Golden Delicious" True,
                Portocala "Sanguinello" 15,
                Portocala "Moro" 12,
                Portocala "Tarocco" 3,
                Portocala "Moro" 12,
                Portocala "Valencia" 2,
                Mar "Golden Delicious" False,
                Mar "Golden" False,
                Mar "Golden" True]

ePortocalaDeSicilia :: Fruct -> Bool 
ePortocalaDeSicilia (Mar _ _) = False 
ePortocalaDeSicilia (Portocala str _) = str `elem` ["Tarocco", "Moro", "Sanguinello"]
test_ePortocalaDeSicilia1 =
    ePortocalaDeSicilia (Portocala "Moro" 12) == True
test_ePortocalaDeSicilia2 =
    ePortocalaDeSicilia (Mar "Ionatan" True) == False

nrFeliiSicilia :: [Fruct] -> Int
nrFeliiSicilia ls = sum [nrfelii| Portocala str nrfelii <- ls, ePortocalaDeSicilia (Portocala str nrfelii)]

test_nrFeliiSicilia = nrFeliiSicilia listaFructe == 52

nrMereViermi :: [Fruct] -> Int
nrMereViermi ls = sum [1 | Mar soi areviermi <- ls, areviermi]

test_nrMereViermi = nrMereViermi listaFructe == 2

type NumeA = String
type Rasa = String
data Animal = Pisica NumeA | Caine NumeA Rasa
    deriving Show

vorbeste :: Animal -> String
vorbeste (Pisica _) = "Meow!"
vorbeste (Caine _ _) = "Woof!"

rasa :: Animal -> Maybe String
rasa (Pisica _) = Nothing
rasa (Caine _ rasaCaine) = Just rasaCaine

data Linie = L [Int]
   deriving Show
data Matrice = M [Linie]
   deriving Show

verifica :: Matrice -> Int -> Bool 
verifica (M matrice) n = foldr ((&&) . (\(L linie) -> sum linie == n)) True matrice
test_verif1 = verifica (M[L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) 10 == False
test_verif2 = verifica (M[L[2,20,3], L[4,21], L[2,3,6,8,6], L[8,5,3,9]]) 25 == True

doarPozN :: Matrice -> Int -> Bool 
doarPozN (M matrice) n = foldr ((&&) . (\(L linie) -> (areN linie && strictPozitive linie) || (not $ areN linie))) True  matrice
    where strictPozitive ls = length ls == length (filter (>0) ls)
          areN ls = length ls == n

testPoz1 = doarPozN (M [L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) 3 == True

testPoz2 = doarPozN (M [L[1,2,-3], L[4,5], L[2,3,6,8], L[8,5,3]]) 3 == False

correct :: Matrice -> Bool 
correct (M []) = True
correct (M [l]) = True 
correct (M ( L l1 : (L l2) : ls)) = length l1 == length l2 && correct (M (L l2 : ls))

testcorect1 = correct (M[L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) == False
testcorect2 = correct (M[L[1,2,3], L[4,5,8], L[3,6,8], L[8,5,3]]) == True
