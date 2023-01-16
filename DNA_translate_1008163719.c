////////////////////////////////////////////////////////////
// CSC A48 - DNA alignment Pt. 1
//
// The goal of this assignment is to write a function that
// translates tripled (sets of 3) DNA nucleotide bases to
// the corresponding aminoacid.
//
// As a brief review of your Biology lessons, DNA is a double
// stranded chain of nucleic-acids, there are 4 types of
// nucleotides denoted by the letters:
//
// A, C, T, G
//
// The sequence of these nucleotides specifies the sequence
// in which aminoacids (the building blocks of proteins)
// are assembled into every single one of the proteins that
// make up the cells of most licing things (there are a 
// few that do not use DNA, opting instead to use the single
// stranded version called RNA, viruses tend to be sneaky
// that way!)
//
// Each set of 3 nucleotides specifies one aminoacid in
// a protein's specification.
//
// The goal of this exercise is for you to write a small
// function that takes in a DNA sequence (a string made up
// of letters ATCG in some sequence) and determines the
// corresponding sequence of aminoacids. Below, you will
// find a table listing each aminoacid, and the sequences
// of DNA nucleotides that specify that aminoacid.
// 
// Note that many aminoacids can be specified by more than
// one triplet!
//
//  Aminoacid   Single letter name	Triplets
//  Isoleucine 		I 		ATT, ATC, ATA
//  Leucine 		L 		CTT, CTC, CTA, CTG, TTA, TTG
//  Valine 			V 		GTT, GTC, GTA, GTG
//  Phenylalanine 	F 		TTT, TTC
//  Methionine 		M 		ATG
//  Cysteine 		C 		TGT, TGC
//  Alanine 		A 		GCT, GCC, GCA, GCG
//  Glycine 		G 		GGT, GGC, GGA, GGG
//  Proline 		P 		CCT, CCC, CCA, CCG
//  Threonine 		T		ACT, ACC, ACA, ACG
//  Serine 			S 		TCT, TCC, TCA, TCG, AGT, AGC
//  Tyrosine 		Y 		TAT, TAC
//  Tryptophan 		W 		TGG
//  Glutamine 		Q 		CAA, CAG
//  Asparagine 		N 		AAT, AAC
//  Histidine 		H 		CAT, CAC
//  Glutamic acid 	E 		GAA, GAG
//  Aspartic acid 	D 		GAT, GAC
//  Lysine 			K 		AAA, AAG
//  Arginine 		R 		CGT, CGC, CGA, CGG, AGA, AGG
//
//  Your task is to determine whether two DNA sequences use the
//  same number of each type of aminoacid (the order of the
//  amino-acids doesn't matter here).
//  To that end, you need to write a function that
//  takes a DNA sequence and converts it to the corresponding
//  sequence of aminoacids, for instance if the input sequence is:
//
//  AAGGAGTGTTTT
//
//  Your function must return
//
//  KECF
//
//  Then you need to write a function that takes in two DNA
//  sequences and determines whether they produce the same
//  numbers of each aminoacid. For example, if the sequence
//  of aminoacids for each of the input DNA sequences is
//
//  AATVKFAA    and    TAAVKAAF
//
//  The function must return 1 (they produce the same number
//  of each aminoacid). However, if the aminoacid sequences
//  are
//
//  TVFAAKVV    and    ECVAATFK
//
//  the function will return 0 (not the same number of each
//  aminoacid).
//
// (c) F. Estrada, March, 2022
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void DNA_sequencing(char inputDNA[1024], char outputAminoAcids[1024])
{
    // This function receives two strings, one that contains a sequence
    // of DNA nucleotides (which MUST be composed of the letters
    // ACGT, no spaces or other symbols can appear here!), and
    // updates an initially empty string 'outputAminoAcids' with the
    // sequence of aminoacids corresponding to the input DNA sequence
    //
    // Try to make this function as compact (fewer lines of code, more
    // elegant, easier to read code) as possible. APply what you've
    // learned in Exercises 6-8, all of which helped you practice
    // using strings!

    // To Do:
    // Complete this function
	
	// Stop codons TAA, TAG, and TGA intentionally ignored
	int i;
	for(i = 0; inputDNA[i*3] != '\0'; i++){
		if (inputDNA[3*i] == 'T'){
			if (inputDNA[3*i+1] == 'T'){
				if ((inputDNA[3*i+2] == 'T')||(inputDNA[3*i+2] == 'C')){
					outputAminoAcids[i] = 'F';
				}
				else{
					outputAminoAcids[i] = 'L';
				}
			}
			else if (inputDNA[3*i+1] == 'C'){
				outputAminoAcids[i] = 'S';
			}
			else if (inputDNA[3*i+1] == 'A'){
				if ((inputDNA[3*i+2] == 'T')||(inputDNA[3*i+2] == 'C')){
					outputAminoAcids[i] = 'Y';
				}
				// else stop
			}
			else{
				if ((inputDNA[3*i+2] == 'T')||(inputDNA[3*i+2] == 'C')){
					outputAminoAcids[i] = 'C';
				}
				else if(inputDNA[3*i+2] == 'G'){
					outputAminoAcids[i] = 'W';
				}
			}
		}
		else if (inputDNA[3*i] == 'C'){
			if (inputDNA[3*i+1] == 'T'){
				outputAminoAcids[i] = 'L';
			}
			else if (inputDNA[3*i+1] == 'C'){
				outputAminoAcids[i] = 'P';
			}
			else if (inputDNA[3*i+1] == 'A'){
				if ((inputDNA[3*i+2] == 'T')||(inputDNA[3*i+2] == 'C')){
					outputAminoAcids[i] = 'H';
				}
				else{
					outputAminoAcids[i] = 'Q';
				}
			}
			else{
				outputAminoAcids[i] = 'R';
			}
		}
		else if (inputDNA[3*i] == 'A'){
			if (inputDNA[3*i+1] == 'T'){
				if (inputDNA[3*i+2] == 'G'){
					outputAminoAcids[i] = 'M';
				}
				else{
					outputAminoAcids[i] = 'I';
				}
			}
			else if (inputDNA[3*i+1] == 'C'){
				outputAminoAcids[i] = 'T';
			}
			else if (inputDNA[3*i+1] == 'A'){
				if ((inputDNA[3*i+2] == 'T')||(inputDNA[3*i+2] == 'C')){
					outputAminoAcids[i] = 'N';
				}
				else{
					outputAminoAcids[i] = 'K';
				}
			}
			else{
				if ((inputDNA[3*i+2] == 'T')||(inputDNA[3*i+2] == 'C')){
					outputAminoAcids[i] = 'S';
				}
				else{
					outputAminoAcids[i] = 'R';
				}
			}
		}
		else{
			if (inputDNA[3*i+1] == 'T'){
				outputAminoAcids[i] = 'V';
			}
			else if (inputDNA[3*i+1] == 'C'){
				outputAminoAcids[i] = 'A';
			}
			else if (inputDNA[3*i+1] == 'A'){
				if ((inputDNA[3*i+2] == 'T')||(inputDNA[3*i+2] == 'C')){
					outputAminoAcids[i] = 'D';
				}
				else{
					outputAminoAcids[i] = 'E';
				}
			}
			else{
				outputAminoAcids[i] = 'G';
			}
		}
	}
	outputAminoAcids[i] = '\0';
}

int amino_matching(char inputDNA1[1024], char inputDNA2[1024])
{
    // This function receives two strings representing DNA
    // sequences. It returns 1 if the sequences produce the
    // same number of each type of aminoacid. Think carefully
    // about the best (simplest?) way to to this.

    // To Do:
    // Complete this function

	// Amino acid order: ACDEF GHIKL MNPQR STVWY
	int countArr[20] = {0};
	for (int i = 0; inputDNA1[i] != '\0'; i++){
		if (inputDNA1[i] == 'A'){
			countArr[0]++;
		}
		else if (inputDNA1[i] == 'C'){
			countArr[1]++;
		}
		else if (inputDNA1[i] == 'D'){
			countArr[2]++;
		}
		else if (inputDNA1[i] == 'E'){
			countArr[3]++;
		}
		else if (inputDNA1[i] == 'F'){
			countArr[4]++;
		}
		else if (inputDNA1[i] == 'G'){
			countArr[5]++;
		}
		else if (inputDNA1[i] == 'H'){
			countArr[6]++;
		}
		else if (inputDNA1[i] == 'I'){
			countArr[7]++;
		}
		else if (inputDNA1[i] == 'K'){
			countArr[8]++;
		}
		else if (inputDNA1[i] == 'L'){
			countArr[9]++;
		}
		else if (inputDNA1[i] == 'M'){
			countArr[10]++;
		}
		else if (inputDNA1[i] == 'N'){
			countArr[11]++;
		}
		else if (inputDNA1[i] == 'P'){
			countArr[12]++;
		}
		else if (inputDNA1[i] == 'Q'){
			countArr[13]++;
		}
		else if (inputDNA1[i] == 'R'){
			countArr[14]++;
		}
		else if (inputDNA1[i] == 'S'){
			countArr[15]++;
		}
		else if (inputDNA1[i] == 'T'){
			countArr[16]++;
		}
		else if (inputDNA1[i] == 'V'){
			countArr[17]++;
		}
		else if (inputDNA1[i] == 'W'){
			countArr[18]++;
		}
		else if (inputDNA1[i] == 'Y'){
			countArr[19]++;
		}
	}
	
	for (int i = 0; inputDNA2[i] != '\0'; i++){
		if (inputDNA2[i] == 'A'){
			countArr[0]--;
		}
		else if (inputDNA2[i] == 'C'){
			countArr[1]--;
		}
		else if (inputDNA2[i] == 'D'){
			countArr[2]--;
		}
		else if (inputDNA2[i] == 'E'){
			countArr[3]--;
		}
		else if (inputDNA2[i] == 'F'){
			countArr[4]--;
		}
		else if (inputDNA2[i] == 'G'){
			countArr[5]--;
		}
		else if (inputDNA2[i] == 'H'){
			countArr[6]--;
		}
		else if (inputDNA2[i] == 'I'){
			countArr[7]--;
		}
		else if (inputDNA2[i] == 'K'){
			countArr[8]--;
		}
		else if (inputDNA2[i] == 'L'){
			countArr[9]--;
		}
		else if (inputDNA2[i] == 'M'){
			countArr[10]--;
		}
		else if (inputDNA2[i] == 'N'){
			countArr[11]--;
		}
		else if (inputDNA2[i] == 'P'){
			countArr[12]--;
		}
		else if (inputDNA2[i] == 'Q'){
			countArr[13]--;
		}
		else if (inputDNA2[i] == 'R'){
			countArr[14]--;
		}
		else if (inputDNA2[i] == 'S'){
			countArr[15]--;
		}
		else if (inputDNA2[i] == 'T'){
			countArr[16]--;
		}
		else if (inputDNA2[i] == 'V'){
			countArr[17]--;
		}
		else if (inputDNA2[i] == 'W'){
			countArr[18]--;
		}
		else if (inputDNA2[i] == 'Y'){
			countArr[19]--;
		}
	}

	for(int i = 0; i < 20; i++){
		if (countArr[i] != 0){
			return 0;
		}
	}

    return 1;
}

#ifndef __testing

int main()
{
	char DNAseq1[1024]="CTTATTGTTCCAATGTGGCGGCACTACACGTGCGTTATC";
	char DNAseq2[1024]="ATTTATTGTACATATCATCGTTGGATGCCCGTAATATTG";
    char DNAseq3[1024]="ATCGTTTGCACGTACCACCGGTGGATGCCAGTTATTCTT";
	char aminoAcids[1024]="";

	printf("Input DNA sequence 1: %s\n",DNAseq1);
	DNA_sequencing(DNAseq1,aminoAcids);
	printf("Output aminoacid sequence 1: %s\n",aminoAcids);

	printf("Input DNA sequence 2: %s\n",DNAseq2);
	DNA_sequencing(DNAseq2,aminoAcids);
	printf("Output aminoacid sequence 2: %s\n",aminoAcids);

	printf("Input DNA sequence 3: %s\n",DNAseq3);
	DNA_sequencing(DNAseq3,aminoAcids);
	printf("Output aminoacid sequence 3: %s\n",aminoAcids);

	if (amino_matching(DNAseq1,DNAseq2)==1)
	{
		printf("Sequence 1 matches sequence 2 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 2 in aminoacids\n");
	}

	if (amino_matching(DNAseq1,DNAseq3)==1)
	{
		printf("Sequence 1 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 3 in aminoacids\n");
	}

	if (amino_matching(DNAseq2,DNAseq3)==1)
	{
		printf("Sequence 2 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 2 does not match sequence 3 in aminoacids\n");
	}

	return 0;
}

#endif
