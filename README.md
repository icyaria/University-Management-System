# Αντικειμενοστραφής Προγραμματισμός
Εργασία 2023-2024 Β' μέρος

Μαρία Καπάκη, ΑΜ: 1115202100051
Δέσποινα Καμπιώτη, ΑΜ: 1115202100285

**ΣΟΚ**
Έχουν μείνει ΜΟΝΟ:
- Να ελέγχουμε ότι όντως ανοίκει το μάθημα στον καθηγητή
- Να μπορεί να τυπώσει ένας φοιτητής την αναλυτική του βαθμολογία για το τρέχων εξάμηνο 
- Να τυπωθούν οι φοιτητές που μπορούν να πάρουν πτυχίο 
- Χρήση exception


Προβλήματα:
1. όταν έχει λάθος input πχ χαρακτήρα αντί για νούμερο στο phone number, το πρόγραμμα κρασάρει και τρέχει για πάντα, ίσως χρειάζεται να χρησιμοποιήσουμε το exception handling που ζητάει έτσι κι αλλιώς και αυτή (αλλιώς if σε καθε input).
2. memory leaks
3. Να τσεκάρει αν ένας καθηγητής ήδη διδάσκει ένα μάθημα πριν τον κάνει assign η secretary

TO DO:
1. Να προσθέτονται τα ECTS ενός μαθήματος αν το πέρασε ο μαθητής (line 306 menu) **DONE**
2. Να μην τυπώνει όλα τα στοιχεία του μαθητή όταν τον βαθμολογούμε (line 306 menu) **DONE**
3. Να ελέγχουμε ότι όντως ανοίκει το μάθημα στον καθηγητή (Line 306 menu) - Δ / Πρόβλημα :') γιατιιι?? ΤΤ
4. Να μην τυπώνει μαθήματα που έχει περάσει ο μαθητής στο enroll και να μην τον αφήνει να κάνει enroll σε αυτά **DONE**
5. Λίστα βαθμών μαθητών όλων των μαθημάτων **DONE**

Εργασία:

B1. Δημιουργήστε μία κλάση Student που κληρονομεί την Person, **DONE**
B2. Δημιουργήστε μία κλάση Professor που κληρονομεί την Person **DONE**
B3. Δημιουργήστε μία κλάση Course **DONE**

- Αρχεία με στοιχεία φοιτητών, καθηγητών και μαθημάτων **DONE**

- Φόρτωση αρχείου φοιτητών στην γραμματεία **DONE**
- Φόρτωση αρχείου καθηγητών στην γραμματεία **DONE**
- Φόρτωση αρχείου μαθημάτων στην γραμματεία **DONE**

- Ενημέρωση αρχείου φοιτητών πριν τον τερματισμό **DONE**
- Ενημέρωση αρχείου καθηγητών πριν τον τερματισμό **DONE**
- Ενημέρωση αρχείου μαθημάτων πριν τον τερματισμό **DONE**

- Να προστεθεί ένας καθηγητής **DONE**
- Να διαφοροποιηθεί ένας καθηγητής **DONE**
- Να διαγραφεί ένας καθηγητής **DONE**
- Να τυπώνονται όλοι οι καθηγητές **DONE**

- Να προστεθεί ένας φοιτητής **DONE**
- Να διαφοροποιηθεί ένας φοιτητής **DONE**
- Να διαγραφεί ένας φοιτητής **DONE**
- Να τυπώνονται όλοι οι φοιτητές **DONE**

- Να προστεθεί ένα μάθημα **DONE**
- Να διαφοροποιηθεί ένα μάθημα **DONE**
- Να διαγραφεί ένα μάθημα **DONE**

- Να οριστούν οι καθηγητές ενός μαθήματος **DONE**
- Να εγγραφεί ένας φοιτητής σε ένα μάθημα **DONE**
- Να εμφανιστούν και να αποθηκευτούν σε ένα αρχείο οι φοιτητές που πέρασαν σε ένα ακαδημαϊκό εξάμηνο ένα συγκεκριμένο μάθημα - **DONE**
- Να μπορεί ένας καθηγητής να τυπώσει τα στατιστικά του εξαμήνου για όλα τα μαθήματα του **DONE**
- Να μπορεί να τυπώσει ένας φοιτητής την αναλυτική του βαθμολογία για το τρέχων εξάμηνο - Μ **έφτιαξα το format - Δ**
- Να μπορεί να τυπώσει ένας φοιτητής την αναλυτική του βαθμολογία για όλα τα έτη **DONE**
- Να τυπωθούν οι φοιτητές που μπορούν να πάρουν πτυχίο - Δ 
- Χρήση exception

//Notes
- Σε κάθε ακαδημαϊκό εξάμηνο η γραμματεία ορίζει τους διδάσκοντες (Professor) ενός μαθήματος (Course) **DONE**
- Οι φοιτητές(Student) εγγράφονται στα μαθήματα που μπορούν, δηλαδή σε μαθήματα τους έτους τους ή παλιότερου **DONE**
- Ο καθηγητής μπορεί να καταχωρήσει τον βαθμό **DONE**