# Exam Prep Projects 📚

Welcome to my collection of projects created while preparing for upcoming exams.  
This repository serves as a study archive, showcasing the concepts, skills, and problem-solving approaches I’ve practiced across different topics.

---

## 🎯 Purpose

The goal of this repository is to:

- Strengthen understanding of core concepts through hands-on practice  
- Organize exam-prep work in one place  
- Demonstrate progress through small, focused projects  
- Provide reusable reference material for future revision

---

# Java Exceptions – Vollständige Übersicht

## 1. Error (Unchecked)

| Error | Beschreibung |
|-------|--------------|
| AssertionError | assert fehlgeschlagen |
| LinkageError | Probleme beim Laden von Klassen |
| BootstrapMethodError | Fehler in dynamischen Methoden |
| ClassCircularityError | Kreisabhängigkeit von Klassen |
| ClassFormatError | Fehler im Bytecode |
| ExceptionInInitializerError | Fehler im static-Initializer |
| IncompatibleClassChangeError | Klassen nicht kompatibel |
| InstantiationError | Klasse konnte nicht instanziiert werden |
| InternalError | Interner VM-Fehler |
| NoClassDefFoundError | Klasse zur Laufzeit nicht gefunden |
| UnsatisfiedLinkError | native Methode fehlt |
| VerifyError | Bytecode-Verifikation fehlgeschlagen |
| OutOfMemoryError | Speicher voll |
| StackOverflowError | Stack übergelaufen |
| VirtualMachineError | Genereller VM-Fehler |


---

## 2. Checked Exceptions – I/O & Filesystem

| Exception | Beschreibung |
|----------|--------------|
| IOException | Generischer I/O-Fehler |
| EOFException | Ende der Datei |
| FileNotFoundException | Datei nicht gefunden |
| InterruptedIOException | I/O unterbrochen |
| MalformedURLException | Ungültige URL |
| UnknownHostException | Host unbekannt |
| UnknownServiceException | Service unbekannt |
| ProtocolException | Fehler im Protokoll |


---

## 3. Checked Exceptions – Reflection & Class Loading

| Exception | Beschreibung |
|----------|--------------|
| ClassNotFoundException | Klasse nicht gefunden |
| CloneNotSupportedException | clone() nicht unterstützt |
| IllegalAccessException | Zugriff auf Klasse/Member verboten |
| InstantiationException | Klasse kann nicht erstellt werden |
| InvocationTargetException | Methode wirft Exception |
| NoSuchFieldException | Feld existiert nicht |
| NoSuchMethodException | Methode existiert nicht |


---

## 4. Checked Exceptions – Concurrency / Threads

| Exception | Beschreibung |
|----------|--------------|
| ExecutionException | Fehler in Future/Thread |
| TimeoutException | Timeout in Thread/Wait |
| BrokenBarrierException | Barrier kaputt |
| InterruptedException | Thread unterbrochen |


---

## 5. Checked Exceptions – SQL / Datenbanken

| Exception | Beschreibung |
|----------|--------------|
| SQLException | Generischer SQL-Fehler |
| SQLDataException | Ungültige Daten |
| SQLIntegrityConstraintViolationException | DB-Constraint verletzt |
| SQLInvalidAuthorizationSpecException | Authentifizierungsfehler |
| SQLNonTransientConnectionException | Dauerhafter DB-Verbindungsfehler |
| SQLTransactionRollbackException | Transaktion zurückgerollt |


---

## 6. Checked Exceptions – Security

| Exception | Beschreibung |
|----------|--------------|
| GeneralSecurityException | Generischer Security-Fehler |
| InvalidKeyException | Ungültiger Schlüssel |
| SignatureException | Fehler in Signatur |
| NoSuchAlgorithmException | Algorithmus existiert nicht |
| CertificateException | Zertifikat ungültig |


---

## 7. Runtime Exceptions – Allgemeine Programmierfehler

| Exception | Beschreibung |
|----------|--------------|
| RuntimeException | Oberklasse aller Runtime-Fehler |
| NullPointerException | Null-Zugriff |
| IllegalArgumentException | Ungültiges Argument |
| NumberFormatException | Fehler beim Parsen |
| IllegalStateException | Objekt in falschem Zustand |
| IndexOutOfBoundsException | Index ungültig |
| ArrayIndexOutOfBoundsException | Array-Index ungültig |
| StringIndexOutOfBoundsException | String-Index ungültig |
| ClassCastException | Falscher Typ |
| UnsupportedOperationException | Methode nicht unterstützt |


---

## 8. Runtime Exceptions – Collections & Data Structures

| Exception | Beschreibung |
|----------|--------------|
| ConcurrentModificationException | gleichzeitige Änderung |
| NoSuchElementException | Element fehlt |
| DuplicateFormatFlagsException | Formatfehler |
| MissingResourceException | Ressource fehlt |


---

## 9. Runtime Exceptions – Math & Arrays

| Exception | Beschreibung |
|----------|--------------|
| ArithmeticException | z. B. Division durch 0 |
| NegativeArraySizeException | negative Arraygröße |


---

## 10. Runtime Exceptions – Networking

| Exception | Beschreibung |
|----------|--------------|
| UnresolvedAddressException | Adresse nicht auflösbar |
| ClosedChannelException | Channel geschlossen |
| NotYetConnectedException | Channel nicht verbunden |


---

## 11. Runtime Exceptions – Reflection (Unchecked)

| Exception | Beschreibung |
|----------|--------------|
| IllegalAccessError | Zugriff verletzt |
| IncompatibleClassChangeError | Bytecode inkompatibel |