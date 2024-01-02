# Αντικειμενοστραφής Προγραμματισμός
Εργασία 2023-2024 Β' μέρος

Μαρία Καπάκη, ΑΜ: 1115202100051
Δέσποινα Καμπιώτη, ΑΜ: 1115202100285


Προβληματα:
1. όταν εχει λαθος input πχ χαρακτηρα αντι για νουμερο στο phone number, το προγραμμα κρασαρει και τρεχει για παντα
ίσως χρειαζεται να χρησιμοποιησουμε το exception handling που ζηταει ετσι κιαλλιως και αυτη (αλλιως if σε καθε input).
2. memory problems, seg fault στο τελος ( αλλαξα τις add student και add professor οποτε δεν δεσμευουν δυναμικα πλεον)
δεν ξερω τι πρεπει να αλλαξω παντως παει να κανει free κατι που δεν ειναι δεσμευμενο :)

Εργασία:

B1. Δημιουργήστε μία κλάση Student που κληρονομεί την Person, **DONE**
B2. Δημιουργήστε μία κλάση Professor που κληρονομεί την Person **DONE**
B3. Δημιουργήστε μία κλάση Course **DONE**

- Αρχεία με στοιχεία φοιτητών, καθηγητών και μαθημάτων **DONE**

- Φόρτωση αρχείου φοιτητών στην γραμματεία **DONE**
- Φόρτωση αρχείου καθηγητών στην γραμματεία **DONE**
- Φόρτωση αρχείου μαθημάτων στην γραμματεία

- Ενημέρωση αρχείου φοιτητών πριν τον τερματισμό
- Ενημέρωση αρχείου καθηγητών πριν τον τερματισμό
- Ενημέρωση αρχείου μαθημάτων πριν τον τερματισμό

- Να προστεθεί ένας καθηγητής **DONE**
- Να διαφοροποιηθεί ένας καθηγητής **DONE**
- Να διαγραφεί ένας καθηγητής **DONE**

- Να προστεθεί ένας φοιτητής **DONE**
- Να διαφοροποιηθεί ένας φοιτητής **DONE**
- Να διαγραφεί ένας φοιτητής **DONE**

- Να προστεθεί ένα μάθημα
- Να διαφοροποιηθεί ένα μάθημα
- Να διαγραφεί ένα μάθημα

- Να οριστούν οι καθηγητές ενός μαθήματος
- Να εγγραφεί ένας φοιτητής σε ένα μάθημα
- Να εμφανιστούν και να αποθηκευτούν σε ένα αρχείο οι φοιτητές που πέρασαν σε ένα ακαδημαϊκό εξάμηνο ένα συγκεκριμένο μάθημα
- Να μπορεί ένας καθηγητής να τυπώσει τα στατιστικά του εξαμήνου για όλα τα μαθήματα του
- Να μπορεί να τυπώσει ένας φοιτητής την αναλυτική του βαθμολογία για το τρέχων εξάμηνο
- Να μπορεί να τυπώσει ένας φοιτητής την αναλυτική του βαθμολογία για όλα τα έτη
- Να τυπωθούν οι φοιτητές που μπορούν να πάρουν πτυχίο
- Χρήση exception

//Notes
- Σε κάθε ακαδημαϊκό εξάμηνο η γραμματεία ορίζει τους διδάσκοντες (Professor) ενός μαθήματος (Course)
- Οι φοιτητές(Student) εγγράφονται στα μαθήματα που μπορούν, δηλαδή σε μαθήματα τους έτους τους ή παλιότερου
- Ο καθηγητής μπορεί να καταχωρήσει τον βαθμό