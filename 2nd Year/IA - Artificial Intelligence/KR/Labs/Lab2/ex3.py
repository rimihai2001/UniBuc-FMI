import cProfile
"""
ncalls: numărul de apeluri
tottime: timpul total (agregat) în care a fost executată funcția curentă
percall: Raportul dintre timpul total și numărul de apeluri (cât a durat în medie o executare a acelei funcții\
cumtime: Timpul cumulat al executării funcției, împreună cu funcțiile apelate de către ea
percall: Se referă la al doilea percall din raport. Reprezintă raportul dintre timpul cumulat (cumtime) și numărul de apeluri (ncalls)
filename_lineno(function): Punctual din program, care a fost evaluat ( de exemplu un număr de linie din program sau un apel de funcție).


"""

"""
Observatie pentru cei absenti la laborator: trebuie sa dati enter după fiecare afișare a cozii/stivei până vă apare o soluție. Afișarea era ca să vedem progresul algoritmului. Puteți să o dezactivați comentând print-ul cu coada/stiva și input()

De asemenea, apelurile algoritmilor sunt la final. Este doar unul dintre ele decomentat. Voi trebuie sa comentati/decomentati apelurile în funcție de ce vă interesează sa rulați.
"""

#informatii despre un nod din arborele de parcurgere (nu din graful initial)
class NodParcurgere:
	def __init__(self, id, info, parinte):
		self.id=id # este indicele din vectorul de noduri
		self.info=info
		self.parinte=parinte #parintele din arborele de parcurgere

	def obtineDrum(self): 
		l=[self.info]
		nod=self
		while nod.parinte is not None:
			l.insert(0, nod.parinte.info)
			nod=nod.parinte
		return l
		
	def afisDrum(self): #returneaza si lungimea drumului
		l=self.obtineDrum()
		print("->".join(l))
		return len(l)


	def contineInDrum(self, infoNodNou):
		#return infoNodNou in self.obtineDrum()
		nodDrum=self
		while nodDrum is not None:
			if(infoNodNou==nodDrum.info):
				return True
			nodDrum=nodDrum.parinte
		
		return False
		
	def __repr__(self):
		sir=""		
		sir+=self.info+"("
		sir+="id = {}, ".format(self.id)
		sir+="drum="
		drum=self.obtineDrum()
		sir+=("->").join(drum)
		sir+=")"
		return(sir)
		

class Graph: #graful problemei
	def __init__(self, noduri, matrice, start, scopuri):
		self.noduri=noduri
		self.matrice=matrice
		self.nrNoduri=len(matrice)
		self.start=start #informatia nodului de start
		self.scopuri=scopuri #lista cu informatiile nodurilor scop

	def indiceNod(self, n):
		return self.noduri.index(n)
		
	#va genera succesorii sub forma de noduri in arborele de parcurgere	
	def genereazaSuccesori(self, nodCurent):
		listaSuccesori=[]
		for i in range(self.nrNoduri):
			if self.matrice[nodCurent.id][i] == 1 and  not nodCurent.contineInDrum(self.noduri[i]):
				nodNou=NodParcurgere(i, self.noduri[i], nodCurent)
				listaSuccesori.append(nodNou)
		return listaSuccesori
		
	def testeaza_scop(self, nodCurent):
		return nodCurent.info in self.scopuri

	def __repr__(self):
		sir=""
		for (k,v) in self.__dict__.items() :
			sir+="{} = {}\n".format(k,v)
		return(sir)
		
		

##############################################################################################	
#                                 Initializare problema                                      #
##############################################################################################		

#pozitia i din vectorul de noduri da si numarul liniei/coloanei corespunzatoare din matricea de adiacenta		
noduri=["a","b","c","d","e","f","g","h","i","j"]

m=[
	[0,1,0,1,1,0,0,0,0,0],
	[1,0,1,0,0,1,0,0,0,0],
	[0,1,0,0,0,1,0,1,0,0],
	[1,0,0,0,0,0,1,0,0,0],
	[1,0,0,0,0,0,0,1,0,0],
	[0,1,1,0,0,0,0,0,0,0],
	[0,0,0,1,0,0,0,0,0,0],
	[0,0,1,0,1,0,0,0,1,1],
	[0,0,0,0,0,0,0,1,0,0],
	[0,0,0,0,0,0,0,1,0,0]
]

start="a"
scopuri=["f","j"]
gr=Graph(noduri, m, start, scopuri)

def depth_first(gr, nrSolutiiCautate=1):
	#vom simula o stiva prin relatia de parinte a nodului curent	
	df(NodParcurgere(gr.noduri.index(gr.start), gr.start, None), nrSolutiiCautate)

				
def df(nodCurent, nrSolutiiCautate):
	if nrSolutiiCautate<=0: #testul acesta s-ar valida doar daca in apelul initial avem df(start,if nrSolutiiCautate=0)
		return nrSolutiiCautate
	print("Stiva actuala: " + "->".join(nodCurent.obtineDrum()))
	input()
	if gr.testeaza_scop(nodCurent):
		print("Solutie: ", end="")
		nodCurent.afisDrum()
		print("\n----------------\n")
		input()
		nrSolutiiCautate-=1
		if nrSolutiiCautate==0:
			return nrSolutiiCautate
	lSuccesori=gr.genereazaSuccesori(nodCurent)	
	for sc in lSuccesori:
		if nrSolutiiCautate!=0:
			print("se expandeaza nodul "+ str(sc.info))
			nrSolutiiCautate=df(sc, nrSolutiiCautate)
			print("se intoarce ->")
	
	return nrSolutiiCautate

"""
Mai jos puteti comenta si decomenta apelurile catre algoritmi. Pentru moment e apelat doar breadth-first
"""

#breadth_first(gr, nrSolutiiCautate=4)
cProfile.run("depth_first(gr, nrSolutiiCautate=2)")
####################################################

