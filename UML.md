#DNA analyzer UML

##class diagram

```plantuml


@startuml
left to right direction
class DnaSequence
{
    - m_data: Nucleoide*
    + DnaSequence()
    + DnaSequence(char*)
    + DnaSequence(string)
    + ~DnaSequence()
    + operator = (&DnaSequence): DnaSequence&
    + operator = (char*): DnaSequence&
    + operator = (String*): DnaSequence&
    + operator = (Nucleotide*): DnaSequence&
    + isDna(char*): bool
    + isDna(string): bool
    + isDna(String): bool
    + getData(): Nucleotide*
    + getLen(): size_t
    + operator == (&DnaSequence): bool
    + operator != (&DnaSequence): bool
    + operator [ ] (size_t): Nucleotide
    + save_to_file(char*): void
    + makeSlice(size_t , size_t): DnaSequence
    + pairDna(): string
    + operator <<(ostream&,DnaSequence&): ostream&
}

class Nucleotide
{
    - m_nuc: char
    + Nucleotide()
    + Nucleotide(char)
    + ~Nucleotide()
    + operator = (&Nucleotide): Nucleotide&
    + operator = (char): Nucleotide&
    + getNuc(): char
    + operator == (&Nucleotide): bool
    + operator != (&Nucleotide): bool
    + isDnaNuc(char): bool
    + getDnaPair(): char
    + operator <<(ostream&,Nucleotide&): ostream&
}

class DnaAnalyzer
{
    - m_id: size_t
    - m_name: string
    - m_dna_seq: DnaSequence
    - m_status: string
    - id: size_t
    + DnaAnalyzer( DnaSequence&, char*)
    + DnaAnalyzer()
    + ~DnaAnalyzer()
    + load(char*, string*): void
    + save(char*): void
    + dup(String&, String&): void
}

class CLI
{
    + navigate()
    + batch()
}


class SeqMtionC
{
    + slice()
    + replace()
    + concat()
    + pair()
}

class SeqMgmntC
{
    + rename()
    + del()
    + save()
}

class SeqAnlsC
{
    + len()
    + find()
    + count()
    + findAll()
}

class CtrlC
{
    + help()
    + list()
    + show()
    + quit()
}

class label
{
    + showLabels()
    + clac()
    + max()
    + min()
    + size()
    + atindex()
}
class dataBase
{
    vector<string>
}

Nucleotide --* DnaSequence
DnaSequence --* DnaAnalyzer
CLI --> CtrlC
CLI --> SeqAnlsC
CLI --> SeqMgmntC
CLI --> SeqMtionC
CLI --> label
CLI --> DnaAnalyzer
DnaAnalyzer --> dataBase
CtrlC --> dataBase
SeqAnlsC --> dataBase
SeqMgmntC --> dataBase
SeqMtionC --> dataBase
label --> dataBase

@enduml

```

##use case diagram

```plantuml
@startuml

left to right direction
skinparam packageStyle rectangle
actor user

rectangle DnaAnalyzer {
user -> (navigate)
(navigate) .> (new): extends
(new) .> (getId): include
(navigate) .> (load): extends
(navigate) .> (dup): extends
(navigate) .> (slice): extends
(navigate) .> (replace): extends
(replace) .> (find): include
(navigate) .> (save): extends
(navigate) .> (quit) : extends
(navigate) .> (len) : extends
(navigate) .> (find) : extends
(navigate) .> (help) : extends
(navigate) .> (list) : extends
(navigate) .> (show) : extends
(navigate) .> (batch) : extends


}

@enduml
```

##package diagram

```plantuml
@startuml

package "Dna analyzer" #DDDDDD {
    DnaAnalyzer *-- DnaSequence
    DnaSequence *-- Nucleotide
    nav <-- DnaAnalyzer
    nav <-- SeqMtionC
    nav <-- SeqMgmntC
    nav <-- SeqAnlsC
    nav <-- label
    nav <-- label
}
package CLI {
    GUI <-- nav
}
@enduml
```