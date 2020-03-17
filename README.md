# dna-analyzer-project-MarwanHalabi
dna-analyzer-project-MarwanHalabi created by GitHub Classroom

## DNA - Intro
DNA sequences are composed of four types of nucleotides; 
The nucleotides are marked A (Adenine), G (Guanine), C (Cytosine) and T (Thymine).
A full DNA molecule usually consists of two strands, connected to each other in base-pair connections: As with Ts, and Cs with Gs. 
Three successive nucleotides generate a codon, which might be chemically "read" in various ways.
A full DNA sequence might be very long - for example, the full human genome holds ~3*109 nucleotides. However, lots of work can be done with relatively short sequences that represent a specific region within the DNA.

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
