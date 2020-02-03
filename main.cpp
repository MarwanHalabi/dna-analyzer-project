#include <iostream>
#include <climits>
#include "gtest/gtest.h"
#include "bits/stdc++.h"
#include "dnaAnalyzer.h"

int main() {
    for (std::string line; std::getline(std::cin, line);) {
        std::cout << line << std::endl;
    }
    return 0;
}
/*
TEST(DnaSequence, NucleotideTest)
{
    Nucleotide N;
    Nucleotide N1 ='A' ;
    Nucleotide N2('T') ;
    Nucleotide N3('C') ;
    Nucleotide N4('G') ;
    Nucleotide N5 = N1;

    ASSERT_EQ(N1.getNuc(),'A');
    ASSERT_EQ(N.getNuc(),'\0');

    ASSERT_TRUE(N1==N5);
    ASSERT_FALSE(N2==N5);
    ASSERT_TRUE(N2!=N5);
    ASSERT_FALSE(N1!=N5);

    N5 = 'A';
    ASSERT_TRUE(N5==N1);
}

TEST(DnaSequence, NucleotideThrowTest)
{
    Nucleotide N;
    char C = 'f';
    ASSERT_ANY_THROW(N.isDnaNuc(C));
    ASSERT_ANY_THROW(Nucleotide N2('f'));
    ASSERT_ANY_THROW(N ='f');
}

TEST(DnaSequence, DNATest) {
    DnaSequence DNA("/home/marvios/CLionProjects/DNA/test.txt");//constrctor by path
    ASSERT_EQ(DNA.getLen(), 6);
    String A = "ACTATGG";
    DnaSequence DNA2(A);
    ASSERT_EQ(DNA2.getLen(),7);


    DnaSequence DNA3 = DNA2;
    ASSERT_EQ(DNA3.getLen(),7);
    ASSERT_TRUE(DNA3 == DNA2);
    ASSERT_FALSE(DNA3 != DNA2);
    ASSERT_FALSE(DNA == DNA2);
    ASSERT_TRUE(DNA != DNA2);

    ASSERT_EQ(DNA3.getData()[0],'A');

    DNA3.save_to_file( "/home/marvios/CLionProjects/DNA/test2.txt");
    DnaSequence DNA4("/home/marvios/CLionProjects/DNA/test2.txt");
    ASSERT_TRUE(DNA4 == DNA3);

    DnaSequence DNA5 = DNA2.makeSlice(0,3);
    A = "ACT";
    DnaSequence DNA6(A);

    ASSERT_TRUE(DNA5 == DNA6);

    A = "ACTG";
    DnaSequence DNA7(A);

    ASSERT_EQ(DNA7.pairDna(),"CGATGCTA");
}

TEST(DnaSequence, DNAThrowTest)
{
    DnaSequence DNA("/home/marvios/CLionProjects/DNA/test.txt");//constrctor by path
    DnaSequence DNA1;
    String A = "ACTATdGGf";
    std::string A1 = "ACTATdGGf";
    char* C = "dfdfd";
    DnaSequence DNA3;

    ASSERT_ANY_THROW(DnaSequence DNA2(A));
    ASSERT_ANY_THROW(DNA3 = A);
    ASSERT_ANY_THROW(DNA3 = C);
    ASSERT_ANY_THROW(DNA.isDna(A));
    ASSERT_ANY_THROW(DNA.isDna(A1));
    ASSERT_ANY_THROW(DNA.isDna(C));
    ASSERT_ANY_THROW(DNA[100]);
    ASSERT_ANY_THROW(DNA1 = DNA.makeSlice(0,30));
    ASSERT_ANY_THROW(DNA1 = DNA.makeSlice(-1,30));
    ASSERT_ANY_THROW(DNA1 = DNA.makeSlice(10,3));
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
*/