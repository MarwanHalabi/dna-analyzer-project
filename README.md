# dna-analyzer-project-MarwanHalabi
dna-analyzer-project-MarwanHalabi created by GitHub Classroom.
The goal of the system is to load, analyze, manipulate and save DNA sequences.

## Description
DNA sequences are composed of four types of nucleotides; 
The nucleotides are marked A (Adenine), G (Guanine), C (Cytosine) and T (Thymine).
A full DNA molecule usually consists of two strands, connected to each other in base-pair connections: As with Ts, and Cs with Gs. 
Three successive nucleotides generate a codon, which might be chemically "read" in various ways.
A full DNA sequence might be very long - for example, the full human genome holds ~3*109 nucleotides. However, lots of work can be done with relatively short sequences that represent a specific region within the DNA.

#### contains:
- DnaSequence class, that represents a DNA sequence (description below).
- Nucleotide class, that represents a DNA nucleotides (description below).
- string class bullied from scrach.
- command design pattern, class diagram provided.
- Command Line Interface.

The system will interact with the user through a CLI (Command Line Interface) that uses the standard I/O. Using that interface, the user will be able to load DNA sequences from files, to analyze them, to manipulate them (e.g., by extracting sequence slices or by modifying the sequence), and to store modified sequences and reports.

The commands are detailed in the following sections.
The Command Line Interface (CLI)
The command line interface allows interaction with the user. Throughout that interface, the user can enter their input and see the application's output. The prompt of the CLI is usually > cmd >>>; it might change when special type of input is required.

There are several groups of commands, such as:
- Sequence Creation Commands: 
  - new. ```> cmd >>> new <sequence> [@<sequence_name>]```
  - load. ```> cmd >>> load <file_name>  [@<sequence_name>]```
  - dup. ```> cmd >>> dup <seq> [@<new_seq_name>]```
- Sequence Manipulation Commands.
  - slice. ```> cmd >>> slice <seq> <from_ind> <to_ind> [: [@<new_seq_name>|@@]]```
  - replace. ```> cmd >>> replace <seq> <index> <new_letter> [: [@<new_seq_name>|@@]]```
  - concat. ```> cmd >>> concat <seq_1> <seq_2> [: [@<new_seq_name>|@@]]```
  - pair. ```> cmd >>> pair <seq> [: [@<new_seq_name>|@@]]```
  - rename. ```> cmd >>> rename <seq> @<new_name>```
  - del. ```> cmd >>> del <seq>```
  - reenum. ```> cmd >>> reenum```
  - save. ```> cmd >>> save <seq> [<filename>]```
- Sequence Analysis Commands:
  - len. ```> cmd >>> len <seq_id>```
  - find. ```> cmd >>> find <seq> <expressed_sub_seq>```
  - count. ```> cmd >>> count <seq> <expressed_sub_seq>```
           ```> cmd >>> count <seq_to_find_in> <seq_to_be_found>```
  - findall. ```> cmd >>> findall <seq> <expressed_sub_seq>```
             ```> cmd >>> findall <seq_to_find_in> <seq_to_be_found>```

## DnaSequence class, that represents a DNA sequence. The class have:
- Constructor that gets a c-string (i.e., a pointer to a sequence of chars, that ends by a null-terminator) consists of the characters {A, C, T, G}.
- Constructor that gets a std::string consists of {A, C, T, G}.
- Support construction and assignment from another DnaSequence.
- Support assignment from c-string and std::string.
- Support streaming out (left-shift operator to std::ostream).
- Support operator==(), operator!=().
- Support operator[] to refer the nucleotide in the relevant index.
- Provide sequence length.
- Slicing to sub dna.
- Pairing (unZIP dna).
- Find a subsequence within a sequence.
- Count the number of occurrences of a subsequence within a sequence.
- Find all the occurrences of a subsequence within a sequence.
- Find Consensus Sequences.

## Nucleotide class, that represents a DNA nucleotides. The class have:
- Constructor that gets a char one of the characters {A, C, T, G}.
- Support construction and assignment from another nucleotides.
- Support assignment from char.
- Support streaming out (left-shift operator to std::ostream).
- Support operator==(), operator!=().
- Provide nucleotide pair.
