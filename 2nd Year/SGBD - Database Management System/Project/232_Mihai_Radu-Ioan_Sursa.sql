--EX 4

create table client(
 id_client number(5) primary key,
 nume_client varchar2(55) not null,
 prenume_client varchar2(55) not null,
 telefon_client varchar2(12),
 adresa_client varchar2(100),
 cnp_client varchar2(15),
 email_client varchar2(55),
 data_inregistrare date not null,
 username_client varchar2(55) not null
);

create table angajat(
 id_angajat number(5) primary key,
 nume_angajat varchar2(55) not null,
 prenume_angajat varchar2(55) not null,
 telefon_angajat varchar2(12),
 adresa_angajat varchar2(100),
 cnp_angajat varchar2(15),
 email_angajat varchar2(55),
 data_angajare date not null,
 post varchar2(55)
);

create table editura(
 id_editura number(5) primary key,
 nume_editura varchar2(55) not null,
 adresa_editura varchar2(100),
 telefon_editura varchar2(12),
 email_editura varchar2(55)
);

create table autor(
 id_autor number(5) primary key,
 nume_autor varchar2(55) not null,
 prenume_autor varchar2(55) not null,
 data_nasterii date
);

create table depozit(
 id_depozit number(5) primary key,
 nume_depozit varchar2(55) not null,
 adresa_depozit varchar2(100),
 telefon_depozit varchar2(12),
 email_depozit varchar2(55)
);

create table carte(
 id_carte number(5) primary key,
 id_editura number(5) not null,
 titlu_carte varchar2(55) not null,
 categorie_carte varchar2(55),
 foreign key (id_editura)references editura (id_editura) on delete cascade
);

create table recenzie(
 id_recenzie number(5) primary key,
 id_client number(5) not null,
 id_carte number(5) not null,
 continut_recenzie varchar2(200),
 data_recenzie date not null,
 numar_stele number(1) not null,
 foreign key (id_client)references client (id_client) on delete cascade,
 foreign key (id_carte)references carte (id_carte) on delete cascade
);

create table comanda(
    id_comanda number(5) primary key,
    id_client number(5) not null,
    data_comanda date not null,
    foreign key (id_client) references client(id_client) on delete cascade
);

create table preluare(
    id_angajat number(5) not null,
    id_comanda number(5) not null,
    data_preluare date not null,
    constraint PK_preluare  primary key (id_angajat, id_comanda),
    foreign key(id_angajat) references angajat(id_angajat) on delete cascade,
    foreign key(id_comanda) references comanda(id_comanda) on delete cascade
);

create table creatie(
    id_carte number(5) not null,
    id_autor number(5) not null,
    constraint PK_creatie  primary key (id_carte, id_autor),
    foreign key(id_carte) references carte(id_carte) on delete cascade,
    foreign key(id_autor) references autor(id_autor) on delete cascade
);

create table plata(
    id_plata number(5) primary key,
    id_comanda number(5) not null,
    id_angajat number(5) not null,
    nume_platitor varchar2(55),
    valuta varchar2(10) not null,
    data_efectuare_plata date not null,
    tip_plata varchar2(55),
    foreign key(id_comanda) references comanda(id_comanda) on delete cascade,
    foreign key(id_angajat) references angajat(id_angajat) on delete cascade
);

create table exemplar(
    id_exemplar number(5) primary key,
    id_carte number(5) not null,
    id_comanda number(5) not null,
    id_depozit number(5) not null,
    an_aparitie_exemplar number(4),
    pret_exemplar numeric(4,2) not null,
    stare_exemplar varchar2(55),
    foreign key(id_carte) references carte(id_carte) on delete cascade,
    foreign key(id_comanda) references comanda(id_comanda) on delete cascade,
    foreign key(id_depozit) references depozit(id_depozit) on delete cascade
);

--EX 5

insert into client values(1, 'Popescu', 'Ioan', '0723595269','Str. Lalelelor 108, Tg. Jiu', '5010304678823','ipop@gmail.com', to_date('23/06/2020', 'DD/MM/YYYY'), 'ipopescu');
insert into client values(2, 'Radu', 'Ioana', '0723293170','Str. Florilor 2, Petrosani', '6010611672723','ioanar@gmail.com', to_date('24/06/2020', 'DD/MM/YYYY'), 'ioanair');
insert into client values(3, 'Mihai', 'Alexandra', '0723464287','Str. Paris 8, Bucuresti', '611020372710','am@gmail.com', to_date('30/08/2020', 'DD/MM/YYYY'), 'alm');
insert into client values(4, 'Banul', 'Radu', '0789124766','Bvd. Libertatii 32, Craiova', '514010777777','radub@gmail.com', to_date('25/02/2020', 'DD/MM/YYYY'), 'radub');
insert into client values(5, 'Aionese', 'Andrei', '0723666666','Str. Diamantelor 8, Botosani', '502030402012','aa@gmail.com', to_date('06/06/2019', 'DD/MM/YYYY'), 'aanda');
insert into client values(6, 'Alexandrescu', 'Paula', '0723868646','Str. Bibliotecii 3, Tg. Jiu', '600030744150','paulaalexandrescu2000@yahoo.com', to_date('12/12/2019', 'DD/MM/YYYY'), 'paulaalexandrescu');
insert into client values(7, 'Fulea', 'Andreea', '0723996996','Str. Turda 44, Urziceni', '605020149374','andre123@gmail.com', to_date('16/08/2020', 'DD/MM/YYYY'), 'andre1234');
insert into client values(8, 'Manea', 'Paul', '0723116256','Str. Sisesti 24, Bucuresti', '511020375780','pman@gmail.com', to_date('11/09/2018', 'DD/MM/YYYY'), 'paman');
insert into client values(9, 'Sorin', 'Maria', '0723099056','Str. Soarelui 88, Galati', null, null, to_date('30/08/2020', 'DD/MM/YYYY'), 'msms');
insert into client values(10, 'Andrei', 'Adriana', '0723887723',null, '6130302737214','aand@gmail.com', to_date('04/02/2020', 'DD/MM/YYYY'), 'adand');


insert into angajat values(1, 'Mihailescu', 'Carina', '0723237924',null, null,'mcarina@gmail.com', to_date('04/02/2020', 'DD/MM/YYYY'), 'Casier');
insert into angajat values(2, 'Mihailescu', 'Dorina', '0723337844',null, '6010302967214','mdorina@gmail.com', to_date('04/02/2020', 'DD/MM/YYYY'), 'Vanzator');
insert into angajat values(3, 'Georgescu', 'Daria', '0723852467','Str. Sisesti 222, Bucuresti', null,'dariageo@gmail.com', to_date('05/02/2020', 'DD/MM/YYYY'), 'Contabil');
insert into angajat values(4, 'Vasilescu', 'Simona', '0723295844','Str. Garii 22, Buftea', '601030234433','vasimona@gmail.com', to_date('08/03/2020', 'DD/MM/YYYY'), 'Responsabil Impachetare');
insert into angajat values(5, 'Popescu', 'Mihaela', '0723196222','Str. Zorilor 11, Buftea', null,'popmiha@gmail.com', to_date('09/04/2020', 'DD/MM/YYYY'), 'Responsabil Impachetare');
insert into angajat values(6, 'Pavaloiu', 'Anca', '0723894370','Str. Sbl. Mihai Cristian Oancea, Bl. 6, Ap.11, Tg. Jiu', '6000308967312','pavaloiuanca@gmail.com', to_date('20/12/2019', 'DD/MM/YYYY'), 'Asistent Vanzari');
insert into angajat values(7, 'Dumitrascu', 'Iulia', '0723742196','Str. Stadionului 123, Petrosani', null,'iuliad@gmail.com', to_date('01/12/2019', 'DD/MM/YYYY'), null);
insert into angajat values(8, 'Mosoi', 'Andrei', '0724592756','Sos. Grivitei 128C, Bucuresti', null,'andreimosoi@gmail.com', to_date('09/12/2020', 'DD/MM/YYYY'), 'Responsabil Inventar');
insert into angajat values(9, 'Gherghe', 'Vladimir', '0723237345','Str. Garii 17, Brasov', '5010203050401','vlag@gmail.com', to_date('03/02/2021', 'DD/MM/YYYY'), 'Serviciu Tehnic');
insert into angajat values(10, 'Ceparu', 'Andrei', '0745063364',null, null,'cepi2001@gmail.com', to_date('05/05/2021', 'DD/MM/YYYY'), 'Om de Serviciu');


insert into editura values(1, 'Editura Univers', 'Str. Dionisie Lupu Nr. 65, Bucuresti', '0758770777', null);
insert into editura values(2, 'Editura Adevarul Holding', null, '0214077650', 'carte@adevarul.ro');
insert into editura values(3, 'Polirom', 'Bvd. Carol I nr. 4, Iasi', '0232214100', 'office@polirom.ro');
insert into editura values(4, 'Editura ART', 'Splaiul Independentei nr. 315-319, Bucuresti', '0744300870', 'comenzi@editura-art.ro');
insert into editura values(5, 'LEDA', 'Calea Plevnei nr. 145, Bucuresti', '0213198822', 'vanzari@edituracorint.ro');
insert into editura values(6, 'Humanitas', 'Pta. Presei Libere nr. 1, Bucuresti', '0214088350', 'vanzari@libhumanitas.ro');
insert into editura values(7, 'Bantam Books', '61-63 Uxbridge Road, London, UK', null, 'bdpublicity@randomhouse.com');
insert into editura values(8, 'Editura Trei', 'O.P. 16, Ghiseul 1, Bucuresti', '0213006090', 'comenzi@editura3.ro');
insert into editura values(9, 'Editura Litera', 'O.P. 53, Bucuresti', '0213196390', 'comenzi@litera.ro');
insert into editura values(10, 'Editura RAO', 'Str. Bargaului, nr. 9-11, Bucuresti', null, 'office@rao.ro');
insert into editura values(11, 'Nemira', 'Str. Iani Buzoiani 14, Bucuresti', '0721747464', 'office@nemira.ro');
insert into editura values(12, 'Weidenfeld and Nicolson', 'Carmelite House 50, London, UK', null, null);

insert into autor values(1, 'Brown', 'Dan', to_date('22/06/1964', 'DD/MM/YYYY'));
insert into autor values(2, 'Bergler', 'Igor', to_date('21/09/1970', 'DD/MM/YYYY'));
insert into autor values(3, 'Vancu', 'Radu', to_date('13/07/1978', 'DD/MM/YYYY'));
insert into autor values(4, 'Zafon', 'Carlos Ruiz', to_date('25/09/1964', 'DD/MM/YYYY'));
insert into autor values(5, 'Sullivan', 'Mark', to_date('28/06/1958', 'DD/MM/YYYY'));
insert into autor values(6, 'Burnet', 'Graeme Macrae', to_date('01/01/1967', 'DD/MM/YYYY'));
insert into autor values(7, 'Orwell', 'George', to_date('25/06/1903', 'DD/MM/YYYY'));
insert into autor values(8, 'Stocker', 'Bram', to_date('08/11/1947', 'DD/MM/YYYY'));
insert into autor values(9, 'Wilde', 'Oscar', to_date('16/10/1854', 'DD/MM/YYYY'));
insert into autor values(10, 'Gerrard', 'Steven', to_date('30/05/1980', 'DD/MM/YYYY'));
insert into autor values(11, 'Jones', 'Lesley-Ann', to_date(null));


insert into depozit values(1, 'Depozitul de Carte', 'Str. Fantanii Nr. 65, Chiajna', '0758777877', 'depozituldecarte@yahoo.com');
insert into depozit values(2, 'Depozitul de Carte Straina', 'Pta.  Romana Nr. 9, Bucuresti', '021379877', 'sitka@sitka.ro');
insert into depozit values(3, 'Depozitul de Carti Vechi', 'Str. Cluj Nr. 88, Bucuresti', '0723667877', 'carteaveche@gmail.com');
insert into depozit values(4, 'Depozitul Cartea Muntelui', 'Str. Postei Nr. 4, Brasov', '0758774513', 'carteamunteluibv@yahoo.com');
insert into depozit values(5, 'Depozitul Ursuletul Cititor', 'Str. Ursului Nr. 1, Ranca', '0758789922', 'ursuletulcititor@gmail.com');
insert into depozit values(6, 'La Raftul cu Carti', 'Str. Stadionului Nr. 4, Buzau', '0238850714', 'laraft@gmail.com');
insert into depozit values(7, 'Depozitul de Carti Horror', 'Str. Castelului Nr. 14, Bran', '0766677666', 'horrorbook@gmail.com');
insert into depozit values(8, 'Books4ALL', 'Str. Turda Nr. 18, Bucuresti', '0217775678', 'books4all@yahoo.com');
insert into depozit values(9, 'RoBooksBuc', 'Bvd. Magheru Nr. 284, Bl. 6, Et. 3, Bucuresti', '0758812877', 'robb@yahoo.com');
insert into depozit values(10, 'Dream and Read', 'Str. Parcului Nr. 2, Tg. Jiu', '0758777899', 'dreamandread2000@yahoo.com');

insert into carte values(1,2,'Dracula','Horror');
insert into carte values(2,1,'Portretul lui Dorian Grey',null);
insert into carte values(3,4,'Un Proiect Sangeros','Horror');
insert into carte values(4,3,'Ferma Animalelor', null);
insert into carte values(5,3,'Umbra Vantului','Thriller');
insert into carte values(6,10,'Biblia Pierduta','Thriller');
insert into carte values(7,8,'Sub Un Cer Sangeriu','Fictiune Istorica');
insert into carte values(8,6,'Transparenta','Fictiune');
insert into carte values(9,9,'6 Povesti cu Draci','Povestiri');
insert into carte values(10,10,'Inferno','Thriller');
insert into carte values(11,11,'Bohemian Rhapsody','Biografie');
insert into carte values(12,7,'Gerrard: My Autobiography','Biografie');

insert into recenzie values(1,2,7,'Recomand',to_date('20/05/2021', 'DD/MM/YYYY'),4);
insert into recenzie values(2,2,8,'Recomand!',to_date('20/05/2021', 'DD/MM/YYYY'),4);
insert into recenzie values(3,2,11,'Foarte buna cartea!',to_date('20/05/2021', 'DD/MM/YYYY'),5);
insert into recenzie values(4,8,12,'Cea mai buna biografie citita vreodata!',to_date('16/05/2021', 'DD/MM/YYYY'),5);
insert into recenzie values(5,3,5,'Inca nu pot dormi din cauza cartii...',to_date('05/05/2021', 'DD/MM/YYYY'),3);
insert into recenzie values(6,8,10,'Nu este mai buna decat Codul lui DaVinci, dar este decenta.',to_date('20/05/2021', 'DD/MM/YYYY'),4);
insert into recenzie values(7,4,2,'Nu recomand sa o cititi!',to_date('28/04/2021', 'DD/MM/YYYY'),2);
insert into recenzie values(8,1,10,null,to_date('05/02/2021', 'DD/MM/YYYY'),3);
insert into recenzie values(9,10,1,null,to_date('22/05/2021', 'DD/MM/YYYY'),5);
insert into recenzie values(10,5,6,'Recomand',to_date('07/03/2021', 'DD/MM/YYYY'),4);

insert into comanda values(1,1,to_date('07/03/2021', 'DD/MM/YYYY'));
insert into comanda values(2,7,to_date('07/02/2021', 'DD/MM/YYYY'));
insert into comanda values(3,4,to_date('05/03/2020', 'DD/MM/YYYY'));
insert into comanda values(4,6,to_date('18/04/2019', 'DD/MM/YYYY'));
insert into comanda values(5,10,to_date('11/05/2021', 'DD/MM/YYYY'));
insert into comanda values(6,8,to_date('11/05/2021', 'DD/MM/YYYY'));
insert into comanda values(7,2,to_date('29/06/2020', 'DD/MM/YYYY'));
insert into comanda values(8,6,to_date('18/02/2021', 'DD/MM/YYYY'));
insert into comanda values(9,2,to_date('19/02/2021', 'DD/MM/YYYY'));
insert into comanda values(10,5,to_date('15/01/2021', 'DD/MM/YYYY'));

insert into preluare values(4,1,to_date('08/03/2021', 'DD/MM/YYYY'));
insert into preluare values(4,2,to_date('07/02/2021', 'DD/MM/YYYY'));
insert into preluare values(4,3,to_date('05/03/2020', 'DD/MM/YYYY'));
insert into preluare values(6,4,to_date('18/04/2019', 'DD/MM/YYYY'));
insert into preluare values(5,5,to_date('12/05/2021', 'DD/MM/YYYY'));
insert into preluare values(5,6,to_date('12/05/2021', 'DD/MM/YYYY'));
insert into preluare values(4,7,to_date('29/06/2020', 'DD/MM/YYYY'));
insert into preluare values(5,8,to_date('19/02/2021', 'DD/MM/YYYY'));
insert into preluare values(6,9,to_date('19/02/2021', 'DD/MM/YYYY'));
insert into preluare values(6,10,to_date('16/01/2021', 'DD/MM/YYYY'));

insert into creatie values(1,8);
insert into creatie values(2,9);
insert into creatie values(3,6);
insert into creatie values(4,7);
insert into creatie values(5,4);
insert into creatie values(6,2);
insert into creatie values(7,5);
insert into creatie values(8,3);
insert into creatie values(9,2);
insert into creatie values(10,1);
insert into creatie values(11,11);
insert into creatie values(12,10);

insert into plata values(1,1,1,null,'RON',to_date('08/03/2021', 'DD/MM/YYYY'),'cash');
insert into plata values(2,2,1,null,'RON',to_date('07/02/2021', 'DD/MM/YYYY'),'card');
insert into plata values(3,3,1,'Alexandrescu','RON',to_date('05/03/2020', 'DD/MM/YYYY'),'cash');
insert into plata values(4,4,1,null,'RON',to_date('18/04/2019', 'DD/MM/YYYY'),'cash');
insert into plata values(5,5,1,null,'RON',to_date('12/05/2021', 'DD/MM/YYYY'),'card');
insert into plata values(6,6,1,null,'RON',to_date('12/05/2021', 'DD/MM/YYYY'),'cec');
insert into plata values(7,7,1,null,'RON',to_date('29/06/2020', 'DD/MM/YYYY'),'cash');
insert into plata values(8,8,1,'Mihai','USD',to_date('20/02/2021', 'DD/MM/YYYY'),'card');
insert into plata values(9,9,1,null,'RON',to_date('19/02/2021', 'DD/MM/YYYY'),'cash');
insert into plata values(10,10,1,'Ghitu','EUR',to_date('18/01/2021', 'DD/MM/YYYY'),'cash');

insert into exemplar values(1,2,1,5,2007,8.50,'Buna');
insert into exemplar values(2,12,2,1,2007,80.70,'Buna');
insert into exemplar values(3,4,3,7,2008,4.50,'Proasta');
insert into exemplar values(4,4,4,4,2008,10.99,'Buna');
insert into exemplar values(5,8,5,9,2005,24.99,'Proasta');
insert into exemplar values(6,5,6,1,2001,45.00,'Foarte Buna');
insert into exemplar values(7,11,7,6,2019,14.00,'Proasta');
insert into exemplar values(8,10,8,9,2015,25.00,null);
insert into exemplar values(9,11,9,10,2020,30.00,null);
insert into exemplar values(10,6,10,1,2015,25.00,'Proasta');
insert into exemplar values(11,5,4,7,2006,30.00,'Buna');
insert into exemplar values(12,5,8,5,2005,22.50,null);
insert into exemplar values(13,5,6,5,2008,17.08,'Proasta');



--EX 6 

CREATE OR REPLACE PROCEDURE detalii_clienti_angajati
(an VARCHAR2)

AS
     TYPE tablou_indexat IS TABLE OF client%ROWTYPE INDEX BY PLS_INTEGER;
     detalii_client tablou_indexat;
     TYPE tablou_imbricat IS TABLE OF angajat%ROWTYPE;
     detalii_angajat tablou_imbricat:= tablou_imbricat();
     nr1 NUMBER;
     nr2 NUMBER;

BEGIN 

    SELECT null INTO nr1
    FROM client 
    WHERE TO_CHAR(data_inregistrare, 'YYYY') <= an AND ROWNUM=1; 
    
    SELECT null INTO nr2
    FROM angajat 
    WHERE TO_CHAR(data_angajare, 'YYYY') <= an AND ROWNUM=1; 

    SELECT * BULK COLLECT INTO detalii_client 
    FROM client 
    WHERE TO_CHAR(data_inregistrare, 'YYYY') <= an;
    
    SELECT * BULK COLLECT INTO detalii_angajat 
    FROM angajat 
    WHERE TO_CHAR(data_angajare, 'YYYY') <= an;
    
    DBMS_OUTPUT.PUT_LINE('CLIENTI: ');
    
    FOR i IN detalii_client.FIRST..detalii_client.LAST LOOP 
    DBMS_OUTPUT.PUT_LINE (detalii_client(i).nume_client || ' '|| detalii_client(i).prenume_client || ' -> ' || NVL(detalii_client(i).email_client,'Adresa email inexistenta'));
    END LOOP;
    
    DBMS_OUTPUT.PUT_LINE('ANGAJATI: ');
    
    FOR i IN detalii_angajat.FIRST..detalii_angajat.LAST LOOP 
    DBMS_OUTPUT.PUT_LINE (detalii_angajat(i).nume_angajat || ' '|| detalii_angajat(i).prenume_angajat || ' -> ' || NVL(detalii_angajat(i).email_angajat,'Adresa email inexistenta'));
    END LOOP;
    

EXCEPTION 
    WHEN NO_DATA_FOUND THEN 
        RAISE_APPLICATION_ERROR(-20000, 'Nu exista clienti sau angajati inregistrati inainte de ' || an); 
    WHEN OTHERS THEN
        RAISE_APPLICATION_ERROR(-20001,'Alta eroare!'); 
END detalii_clienti_angajati; 
/

--Testare:

SET SERVEROUTPUT ON;
execute detalii_clienti_angajati(2021);
/

execute detalii_clienti_angajati(2001);
/


-- Ex 7

CREATE OR REPLACE PROCEDURE
        top3(an VARCHAR2) IS
    CURSOR c IS
        SELECT idc, numar FROM
        (SELECT e.id_carte idc, COUNT(*) numar
        FROM exemplar e
        JOIN comanda co ON (co.id_comanda = e.id_comanda)
        WHERE TO_CHAR(co.data_comanda,'YYYY') = an 
        GROUP BY id_carte
        ORDER BY 2 DESC,1)
        WHERE ROWNUM<=3;
    n1 NUMBER;
    n2 NUMBER;
BEGIN
    SELECT idc, numar INTO n1, n2 
    FROM
        (SELECT e.id_carte idc, COUNT(*) numar
        FROM exemplar e
        JOIN comanda co ON (co.id_comanda = e.id_comanda)
        WHERE TO_CHAR(co.data_comanda,'YYYY') = an 
        GROUP BY id_carte
        ORDER BY 2 DESC,1)
        WHERE ROWNUM=1;
    FOR i IN c LOOP
        DBMS_OUTPUT.PUT_LINE ('ID Carte: ' || i.idc || ' -> Numar comenzi in ' || an || ': '|| i.numar);
    END LOOP;
EXCEPTION 
    WHEN NO_DATA_FOUND THEN 
        RAISE_APPLICATION_ERROR(-20000, 'Nu exista carti vandute in ' || an); 
    WHEN OTHERS THEN 
        RAISE_APPLICATION_ERROR(-20001,'Alta eroare!'); 
END top3;
/

--Testare:

BEGIN
    top3(2021);
END;
/   

BEGIN
    top3(2001);
END;
/   


-- Ex 8

CREATE OR REPLACE FUNCTION reducere_editura
    (v_nume editura.nume_editura%TYPE DEFAULT 'Nemira') 
RETURN NUMBER IS 
    pret_total NUMBER(10,2); 
    id_ed editura.id_editura%TYPE;
BEGIN 
    SELECT id_editura
    INTO id_ed 
    FROM editura e
    WHERE upper(nume_editura)=upper(v_nume);
    
    SELECT SUM(pret_exemplar-(5/100)*pret_exemplar) 
    INTO pret_total 
    FROM editura e 
    JOIN carte c ON (c.id_editura=e.id_editura) 
    JOIN exemplar ex ON (ex.id_carte=c.id_carte) 
    WHERE upper(nume_editura)=upper(v_nume); 
    
    IF pret_total >= 100 THEN
        pret_total := pret_total - (10/100)*pret_total;
    END IF;
    
    RETURN pret_total; 
    
EXCEPTION 
    WHEN NO_DATA_FOUND THEN 
        RAISE_APPLICATION_ERROR(-20000, 'Editura cautata nu exista.'); 
    WHEN TOO_MANY_ROWS THEN 
        RAISE_APPLICATION_ERROR(-20001, 'Exista mai multe edituri cu acest nume!'); 
    WHEN OTHERS THEN 
        RAISE_APPLICATION_ERROR(-20002,'Alta eroare!'); 
END reducere_editura; 
/

--Testare:

SET SERVEROUTPUT ON;
BEGIN 
    DBMS_OUTPUT.PUT_LINE('Pretul final este '|| reducere_editura('Rao')); 
END; 
/

BEGIN 
    DBMS_OUTPUT.PUT_LINE('Pretul final este '|| reducere_editura); 
END; 
/

BEGIN 
    DBMS_OUTPUT.PUT_LINE('Pretul final este '|| reducere_editura('Editura RAO')); 
END; 
/

BEGIN 
    DBMS_OUTPUT.PUT_LINE('Pretul final este '|| reducere_editura('Polirom')); 
END; 
/



-- Ex 9

CREATE OR REPLACE PROCEDURE 
p9(nume_c client.nume_client%TYPE) 
IS ccod client.id_client%TYPE; 
CURSOR c1 IS 
    SELECT c.nume_client ||' ' || c.prenume_client as NumeClient, data_comanda, nume_angajat ||' '|| prenume_angajat as NumeAngajat, tip_plata 
    FROM client c
    JOIN comanda co ON (c.id_client=co.id_client) 
    JOIN preluare p ON (p.id_comanda=co.id_comanda) 
    JOIN angajat a ON (p.id_angajat=a.id_angajat)
    JOIN plata pl ON (pl.id_comanda=co.id_comanda)
    WHERE UPPER(c.nume_client)=UPPER(nume_c)
    ORDER BY co.data_comanda DESC, p.data_preluare DESC, a.nume_angajat; 
BEGIN 
    SELECT id_client 
    INTO ccod 
    FROM client c
    WHERE UPPER(c.nume_client)=UPPER(nume_c); 
    DBMS_OUTPUT.PUT_LINE('Clientul cu id ' || ccod ||': '); 
    DBMS_OUTPUT.NEW_LINE(); 
    DBMS_OUTPUT.PUT_LINE('---------------------------------------------------------------------'); 
    FOR i in c1 LOOP 
        DBMS_OUTPUT.PUT_LINE('Nume complet: ' || i.NumeClient); 
        DBMS_OUTPUT.NEW_LINE();
        DBMS_OUTPUT.PUT_LINE('Data comanda: ' || i.data_comanda); 
        DBMS_OUTPUT.NEW_LINE();  
        DBMS_OUTPUT.PUT_LINE('Angajat: ' || i.NumeAngajat); 
        DBMS_OUTPUT.NEW_LINE();  
        DBMS_OUTPUT.PUT_LINE('Tip Plata: ' || i.tip_plata); 
        DBMS_OUTPUT.NEW_LINE();  
        DBMS_OUTPUT.PUT_LINE('---------------------------------------------------------------------');
    END LOOP; 

EXCEPTION 
    WHEN NO_DATA_FOUND THEN 
        RAISE_APPLICATION_ERROR(-20000, 'Clientul cu numele respectiv nu exista.');
     WHEN TOO_MANY_ROWS THEN 
        RAISE_APPLICATION_ERROR(-20001, 'Mai multi clienti cu acelasi nume'); 
    WHEN OTHERS THEN 
        RAISE_APPLICATION_ERROR(-20002,'Alta eroare!'); 
END p9; 
/

--Testare:

SET SERVEROUTPUT ON;
BEGIN
p9('xcv');
END;

BEGIN
p9('Andrei');
END;

BEGIN
p9('Radu');
END;




-- Ex 10

CREATE OR REPLACE TRIGGER insert_invalid 
BEFORE INSERT OR UPDATE ON client 
BEGIN 
    IF (TO_CHAR(SYSDATE,'D') = 1) THEN
        RAISE_APPLICATION_ERROR(-20000,'Tabelul nu poate fi actualizat. Incercati din nou Luni!'); 
    ELSIF (TO_CHAR(SYSDATE,'HH24') NOT BETWEEN 8 and 20) THEN
        RAISE_APPLICATION_ERROR(-20001,'Tabelul nu poate fi actualizat decat in timpul programului!'); 
    END IF;
END;
/

--Testare:

insert into client values(500, 'Radu', 'Mihai', '0723293122','Str. Fabricii 2, Braila', '6010611672883','rmi_m@gmail.com', sysdate+5, 'rmih');




-- Ex 11

CREATE OR REPLACE TRIGGER pret_stare
BEFORE INSERT OR UPDATE ON exemplar
FOR EACH ROW
WHEN (NEW.pret_exemplar > OLD.pret_exemplar AND OLD.stare_exemplar != 'Foarte Buna')
BEGIN 
    RAISE_APPLICATION_ERROR(-20002, 'Pretul nu poate fi marit din cauza starii cartii');
END;
/

--Testare:

UPDATE exemplar
SET pret_exemplar=pret_exemplar+1;



-- Ex 12

CREATE TABLE actiuni_baza_date 
    (nume_baza_date VARCHAR2(100),
    user_activ VARCHAR2(100),
    actiune VARCHAR2(100),
    tip_obiect_actiune VARCHAR2(100),
    nume_obiect_actiune VARCHAR2(100),
    data_actiune DATE);

CREATE OR REPLACE TRIGGER ldd_trigger 
AFTER CREATE OR DROP OR ALTER ON DATABASE 
BEGIN 
    INSERT INTO actiuni_baza_date VALUES 
    (SYS.DATABASE_NAME, SYS.LOGIN_USER, SYS.SYSEVENT, SYS.DICTIONARY_OBJ_TYPE, SYS.DICTIONARY_OBJ_NAME, SYSDATE); 
END; 
/

--Testare:

CREATE TABLE testare 
    (testare VARCHAR2(100));
    
DROP TABLE testare;
    
SELECT * FROM actiuni_baza_date;


-- Ex 13

CREATE OR REPLACE PACKAGE pachet_ex13
IS  
    PROCEDURE detalii_clienti_angajati
        (an VARCHAR2);
    PROCEDURE top3
        (an VARCHAR2); 
    FUNCTION reducere_editura
    (v_nume editura.nume_editura%TYPE DEFAULT 'Nemira') 
        RETURN NUMBER;
    PROCEDURE 
        p9(nume_c client.nume_client%TYPE);
END pachet_ex13;
/

CREATE OR REPLACE PACKAGE BODY pachet_ex13
IS
    PROCEDURE detalii_clienti_angajati
(an VARCHAR2)

    AS
     TYPE tablou_indexat IS TABLE OF client%ROWTYPE INDEX BY PLS_INTEGER;
     detalii_client tablou_indexat;
     TYPE tablou_imbricat IS TABLE OF angajat%ROWTYPE;
     detalii_angajat tablou_imbricat:= tablou_imbricat();
     nr1 NUMBER;
     nr2 NUMBER;

    BEGIN 

    SELECT null INTO nr1
    FROM client 
    WHERE TO_CHAR(data_inregistrare, 'YYYY') <= an AND ROWNUM=1; 
    
    SELECT null INTO nr2
    FROM angajat 
    WHERE TO_CHAR(data_angajare, 'YYYY') <= an AND ROWNUM=1; 

    SELECT * BULK COLLECT INTO detalii_client 
    FROM client 
    WHERE TO_CHAR(data_inregistrare, 'YYYY') <= an;
    
    SELECT * BULK COLLECT INTO detalii_angajat 
    FROM angajat 
    WHERE TO_CHAR(data_angajare, 'YYYY') <= an;
    
    DBMS_OUTPUT.PUT_LINE('CLIENTI: ');
    
    FOR i IN detalii_client.FIRST..detalii_client.LAST LOOP 
    DBMS_OUTPUT.PUT_LINE (detalii_client(i).nume_client || ' '|| detalii_client(i).prenume_client || ' -> ' || NVL(detalii_client(i).email_client,'Adresa email inexistenta'));
    END LOOP;
    
    DBMS_OUTPUT.PUT_LINE('ANGAJATI: ');
    
    FOR i IN detalii_angajat.FIRST..detalii_angajat.LAST LOOP 
    DBMS_OUTPUT.PUT_LINE (detalii_angajat(i).nume_angajat || ' '|| detalii_angajat(i).prenume_angajat || ' -> ' || NVL(detalii_angajat(i).email_angajat,'Adresa email inexistenta'));
    END LOOP;
    

    EXCEPTION 
        WHEN NO_DATA_FOUND THEN 
            RAISE_APPLICATION_ERROR(-20000, 'Nu exista clienti sau angajati inregistrati inainte de ' || an); 
        WHEN OTHERS THEN
            RAISE_APPLICATION_ERROR(-20001,'Alta eroare!'); 
    END detalii_clienti_angajati;
    
    PROCEDURE
        top3(an VARCHAR2) IS
    CURSOR c IS
        SELECT idc, numar FROM
        (SELECT e.id_carte idc, COUNT(*) numar
        FROM exemplar e
        JOIN comanda co ON (co.id_comanda = e.id_comanda)
        WHERE TO_CHAR(co.data_comanda,'YYYY') = an 
        GROUP BY id_carte
        ORDER BY 2 DESC,1)
        WHERE ROWNUM<=3;
    n1 NUMBER;
    n2 NUMBER;
    BEGIN
    SELECT idc, numar INTO n1, n2 
    FROM
        (SELECT e.id_carte idc, COUNT(*) numar
        FROM exemplar e
        JOIN comanda co ON (co.id_comanda = e.id_comanda)
        WHERE TO_CHAR(co.data_comanda,'YYYY') = an 
        GROUP BY id_carte
        ORDER BY 2 DESC,1)
        WHERE ROWNUM=1;
    FOR i IN c LOOP
        DBMS_OUTPUT.PUT_LINE ('ID Carte: ' || i.idc || ' -> Numar comenzi in ' || an || ': '|| i.numar);
    END LOOP;
    EXCEPTION 
        WHEN NO_DATA_FOUND THEN 
            RAISE_APPLICATION_ERROR(-20000, 'Nu exista carti vandute in ' || an); 
        WHEN OTHERS THEN 
            RAISE_APPLICATION_ERROR(-20001,'Alta eroare!'); 
    END top3;
    
    FUNCTION reducere_editura
    (v_nume editura.nume_editura%TYPE DEFAULT 'Nemira') 
RETURN NUMBER IS 
    pret_total NUMBER(10,2); 
    id_ed editura.id_editura%TYPE;
BEGIN 
    SELECT id_editura
    INTO id_ed 
    FROM editura e
    WHERE upper(nume_editura)=upper(v_nume);
    
    SELECT SUM(pret_exemplar-(5/100)*pret_exemplar) 
    INTO pret_total 
    FROM editura e 
    JOIN carte c ON (c.id_editura=e.id_editura) 
    JOIN exemplar ex ON (ex.id_carte=c.id_carte) 
    WHERE upper(nume_editura)=upper(v_nume);
    
    IF pret_total >= 100 THEN
        pret_total := pret_total - (10/100)*pret_total;
    END IF;

    
    RETURN pret_total; 
    
EXCEPTION 
    WHEN NO_DATA_FOUND THEN 
        RAISE_APPLICATION_ERROR(-20000, 'Editura cautata nu exista.'); 
    WHEN TOO_MANY_ROWS THEN 
        RAISE_APPLICATION_ERROR(-20001, 'Exista mai multe edituri cu acest nume!'); 
    WHEN OTHERS THEN 
        RAISE_APPLICATION_ERROR(-20002,'Alta eroare!'); 
END reducere_editura; 

PROCEDURE 
p9(nume_c client.nume_client%TYPE) 
IS ccod client.id_client%TYPE; 
CURSOR c1 IS 
    SELECT c.nume_client ||' ' || c.prenume_client as NumeClient, data_comanda, nume_angajat ||' '|| prenume_angajat as NumeAngajat, tip_plata 
    FROM client c
    JOIN comanda co ON (c.id_client=co.id_client) 
    JOIN preluare p ON (p.id_comanda=co.id_comanda) 
    JOIN angajat a ON (p.id_angajat=a.id_angajat)
    JOIN plata pl ON (pl.id_comanda=co.id_comanda)
    WHERE UPPER(c.nume_client)=UPPER(nume_c)
    ORDER BY co.data_comanda DESC, p.data_preluare DESC, a.nume_angajat; 
BEGIN 
    SELECT id_client 
    INTO ccod 
    FROM client c
    WHERE UPPER(c.nume_client)=UPPER(nume_c); 
    DBMS_OUTPUT.PUT_LINE('Clientul cu id ' || ccod ||': '); 
    DBMS_OUTPUT.NEW_LINE(); 
    DBMS_OUTPUT.PUT_LINE('---------------------------------------------------------------------'); 
    FOR i in c1 LOOP 
        DBMS_OUTPUT.PUT_LINE('Nume complet: ' || i.NumeClient); 
        DBMS_OUTPUT.NEW_LINE();
        DBMS_OUTPUT.PUT_LINE('Data comanda: ' || i.data_comanda); 
        DBMS_OUTPUT.NEW_LINE();  
        DBMS_OUTPUT.PUT_LINE('Angajat: ' || i.NumeAngajat); 
        DBMS_OUTPUT.NEW_LINE();  
        DBMS_OUTPUT.PUT_LINE('Tip Plata: ' || i.tip_plata); 
        DBMS_OUTPUT.NEW_LINE();  
        DBMS_OUTPUT.PUT_LINE('---------------------------------------------------------------------');
    END LOOP; 
    
EXCEPTION 
    WHEN NO_DATA_FOUND THEN 
        RAISE_APPLICATION_ERROR(-20000, 'Clientul cu numele respectiv nu exista.');
     WHEN TOO_MANY_ROWS THEN 
        RAISE_APPLICATION_ERROR(-20001, 'Mai multi clienti cu acelasi nume'); 
    WHEN OTHERS THEN 
        RAISE_APPLICATION_ERROR(-20002,'Alta eroare!'); 
END p9; 
END pachet_ex13;
/

--TESTARE:

SET SERVEROUTPUT ON;

execute pachet_ex13.detalii_clienti_angajati(2021);
/

BEGIN
    pachet_ex13.top3(2021);
END;
/ 

BEGIN 
    DBMS_OUTPUT.PUT_LINE('Pretul final este '|| pachet_ex13.reducere_editura('Editura Rao')); 
END; 
/

BEGIN
    pachet_ex13.p9('Radu');
END;

--EX 14;

CREATE OR REPLACE PACKAGE pachet_ex14
AS
     TYPE v_id_dep IS VARRAY(100) OF depozit.id_depozit%TYPE;
     TYPE v_carti IS VARRAY(100) OF carte.titlu_carte%TYPE;
     TYPE matrice_titluri_dep IS VARRAY(100) OF v_carti;
     TYPE info_angajat IS RECORD (a_id angajat.id_angajat%TYPE,
                                     a_nu angajat.nume_angajat%TYPE,
                                     a_prnu angajat.prenume_angajat%TYPE);
     TYPE detalii_angajat IS TABLE OF info_angajat;
     
     TYPE info_comenzi IS RECORD (c_id comanda.id_comanda%TYPE,
                                     data_p preluare.data_preluare%TYPE,
                                     data_c comanda.data_comanda%TYPE);
     TYPE detalii_comenzi IS TABLE OF info_comenzi INDEX BY PLS_INTEGER;
     
     TYPE info_rec IS RECORD (c_id client.id_client%TYPE,
                                 c_nu client.nume_client%TYPE,
                                 c_prnu client.prenume_client%TYPE,
                                 c_mail client.email_client%TYPE,
                                 c_uname client.username_client%TYPE,
                                 r_cont recenzie.continut_recenzie%TYPE,
                                 r_stele recenzie.numar_stele%TYPE,
                                 car_titlu carte.titlu_carte%TYPE);
     TYPE detalii_rec IS TABLE OF info_rec;
     
     PROCEDURE afisare_angajati_neperformanti;
     PROCEDURE afisare_depozitare_carti;
     
     FUNCTION intarziere_comenzi
        (an_comenzi NUMBER DEFAULT 2021) 
        RETURN NUMBER;
        
     FUNCTION avertizare_review
        (nr_star NUMBER DEFAULT 2.5)
        RETURN NUMBER;
     
END pachet_ex14;

CREATE OR REPLACE PACKAGE BODY pachet_ex14
AS

    PROCEDURE afisare_angajati_neperformanti
    AS
    v_angj detalii_angajat := detalii_angajat();
    TYPE tablou_agj IS TABLE OF angajat.id_angajat%TYPE;
    tab_id_ang tablou_agj:= tablou_agj();
    indx1 NUMBER;
    indx2 NUMBER;
    BEGIN
    
    SELECT id_angajat, nume_angajat, prenume_angajat
    BULK COLLECT INTO v_angj
    FROM angajat
    WHERE LOWER(post)!='om de serviciu' 
    AND LOWER(post)!='responsabil inventar'
    AND LOWER(post)!='serviciu tehnic'
    AND LOWER(post)!='contabil'; 
    
    SELECT DISTINCT * BULK COLLECT INTO tab_id_ang
    FROM
    (SELECT DISTINCT id_angajat
    FROM preluare
    UNION
    SELECT DISTINCT id_angajat
    FROM plata) ;
    
    FOR i IN v_angj.FIRST..v_angj.LAST LOOP
        indx1:=0;
        FOR j IN tab_id_ang.FIRST..tab_id_ang.LAST LOOP 
            IF v_angj(i).a_id = tab_id_ang(j) THEN
                indx1:=1;
            END IF;
        END LOOP;
        IF indx1=0 THEN
            DBMS_OUTPUT.PUT_LINE('----------------');
            DBMS_OUTPUT.PUT_LINE(v_angj(i).a_id);
            DBMS_OUTPUT.PUT_LINE(v_angj(i).a_nu);
            DBMS_OUTPUT.PUT_LINE(v_angj(i).a_prnu);
            DBMS_OUTPUT.PUT_LINE('----------------');
        END IF;
    END LOOP;
    
    EXCEPTION 
        WHEN NO_DATA_FOUND THEN 
            RAISE_APPLICATION_ERROR(-20000, 'Nu exista date pentru a fi introduse in tabel.'); 
        WHEN OTHERS THEN 
            RAISE_APPLICATION_ERROR(-20001,'Alta eroare!');
    
    END afisare_angajati_neperformanti;
    
    ------------------------------------------------------------------------------------
    
    FUNCTION intarziere_comenzi
        (an_comenzi NUMBER DEFAULT 2021) 
    RETURN NUMBER IS 
        int_procent NUMBER(10,2);
        v_com detalii_comenzi;
        nr_com NUMBER;
        nr_com_intarziate NUMBER;
        nrtest NUMBER;
    BEGIN 
        nr_com := 0;
        nr_com_intarziate := 0;
        
        SELECT null INTO nrtest
        FROM preluare p, comanda c
        WHERE p.id_comanda = c.id_comanda
        AND TO_CHAR(c.data_comanda, 'YYYY') = an_comenzi;

        SELECT p.id_comanda, p.data_preluare, c.data_comanda
        BULK COLLECT INTO v_com
        FROM preluare p, comanda c
        WHERE p.id_comanda = c.id_comanda
        AND TO_CHAR(c.data_comanda, 'YYYY') = an_comenzi;
        
        FOR i IN v_com.FIRST..v_com.LAST LOOP
            nr_com := nr_com+1;
            
            IF (v_com(i).data_p - v_com(i).data_c)>0 THEN
                nr_com_intarziate := nr_com_intarziate + 1;
            END IF;
                    
        END LOOP;
        
        int_procent := nr_com_intarziate / nr_com * 100;
        
        
        RETURN int_procent; 
        
    EXCEPTION 
        WHEN NO_DATA_FOUND THEN 
            RAISE_APPLICATION_ERROR(-20000, 'Nu exista comenzi in anul cautat.'); 
        WHEN OTHERS THEN 
            RAISE_APPLICATION_ERROR(-20001,'Alta eroare!'); 
    END intarziere_comenzi;
    
    -------------------------------------------------------------------------------------
    
    PROCEDURE afisare_depozitare_carti
    AS
        vector_id_depozit v_id_dep := v_id_dep();
        m_depozitare matrice_titluri_dep := matrice_titluri_dep();
    BEGIN
        SELECT id_depozit
        BULK COLLECT INTO vector_id_depozit
        FROM depozit;
        
        FOR i IN vector_id_depozit.FIRST..vector_id_depozit.LAST LOOP
            m_depozitare.extend();
            SELECT c.titlu_carte
            BULK COLLECT INTO m_depozitare(i)
            FROM carte c
            JOIN exemplar e ON (c.id_carte = e.id_carte)
            JOIN depozit d ON (e.id_depozit = d.id_depozit)
            WHERE d.id_depozit = i;
        END LOOP;
        
        DBMS_OUTPUT.PUT_LINE('----------------------------');
        FOR i IN m_depozitare.FIRST..m_depozitare.LAST LOOP
            DBMS_OUTPUT.PUT('Depozitul numarul ' || i || ':');
            IF m_depozitare(i).COUNT > 0 THEN
                FOR j IN 1..m_depozitare(i).COUNT LOOP
                    DBMS_OUTPUT.PUT(m_depozitare(i)(j) || ';  ');
                END LOOP;
            ELSE
                DBMS_OUTPUT.PUT('Nu au fost vandute exemplare din acest depozit');
            END IF;
            DBMS_OUTPUT.PUT_LINE('');
            DBMS_OUTPUT.PUT_LINE('----------------------------');
        END LOOP;
        
        EXCEPTION 
        WHEN NO_DATA_FOUND THEN 
            RAISE_APPLICATION_ERROR(-20000, 'Nu exista date pentru a fi introduse in tabel.'); 
        WHEN OTHERS THEN 
            RAISE_APPLICATION_ERROR(-20001,'Alta eroare!');
        
        
    END afisare_depozitare_carti;
    
    --------------------------------------------------------------------------------------------
    
    FUNCTION avertizare_review
        (nr_star NUMBER DEFAULT 2.5)
        RETURN NUMBER IS
            v_rec detalii_rec := detalii_rec();
            nr_r NUMBER;
            bool_verif NUMBER;
            
        BEGIN
            nr_r := 0;
            
            SELECT c.id_client, c.nume_client, c.prenume_client, c.email_client, c.username_client, r.continut_recenzie, r.numar_stele, car.titlu_carte 
            BULK COLLECT INTO v_rec
            FROM client c
            JOIN recenzie r ON (c.id_client = r.id_client)
            JOIN carte car ON (car.id_carte = r.id_carte)
            ORDER BY c.id_client;
            
            FOR i IN v_rec.FIRST..v_rec.LAST LOOP
            
                bool_verif := 0;
                
                IF v_rec(i).r_stele <= nr_star THEN
                    bool_verif := 1;
                    DBMS_OUTPUT.PUT_LINE('Posibile probleme cu recenzia ' || v_rec(i).car_titlu || ' de ' || v_rec(i).c_uname);
                    DBMS_OUTPUT.PUT_LINE('Cauza: Rating foarte mic!');
                    DBMS_OUTPUT.PUT_LINE('----------------------------');
                END IF;
                
                IF LENGTH(v_rec(i).r_cont) <= 10 THEN
                    bool_verif := 1;
                    DBMS_OUTPUT.PUT_LINE('Posibile probleme cu recenzia ' || v_rec(i).car_titlu || ' de ' || v_rec(i).c_uname);
                    DBMS_OUTPUT.PUT_LINE('Cauza: Recenzie mult prea scurta!');
                    DBMS_OUTPUT.PUT_LINE('----------------------------');
                END IF;
                
                IF bool_verif = 1 THEN
                    nr_r := nr_r + 1;
                END IF;
            END LOOP;
            
        RETURN nr_r;
        
        EXCEPTION
            WHEN NO_DATA_FOUND THEN 
                RAISE_APPLICATION_ERROR(-20000, 'Nu exista date pentru a fi introduse in tabel.');
            WHEN OTHERS THEN 
                RAISE_APPLICATION_ERROR(-20001,'Eroare necunoscuta! Incercati din nou.'); 

    END avertizare_review;

END pachet_ex14;

--------------------------------------Testare:
SET SERVEROUTPUT ON;
BEGIN
    pachet_ex14.afisare_angajati_neperformanti;
END;

BEGIN
    DBMS_OUTPUT.PUT_LINE('Procent comenzi intarziate: ' || pachet_ex14.intarziere_comenzi(2021));
END;

BEGIN
    pachet_ex14.afisare_depozitare_carti;
END;

BEGIN
    
    DBMS_OUTPUT.PUT_LINE('Exista posibile probleme cu ' || pachet_ex14.avertizare_review(2) || ' recenzii. Verificati tabelul de mai sus!');
END;



--DROP--
DROP PACKAGE pachet_ex14;
DROP PACKAGE pachet_ex13;
DROP TRIGGER ldd_trigger;
DROP TABLE actiuni_baza_date;
DROP TRIGGER insert_invalid;
DROP TRIGGER pret_stare;
DROP PROCEDURE p9;
DROP PROCEDURE top3;
DROP PROCEDURE detalii_clienti_angajati;
DROP FUNCTION reducere_editura;


drop table exemplar;
drop table plata;
drop table creatie;
drop table preluare;
drop table comanda;
drop table recenzie;
drop table carte;
drop table depozit;
drop table autor;
drop table editura;
drop table angajat;
drop table client;