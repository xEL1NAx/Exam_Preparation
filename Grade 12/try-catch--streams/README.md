# Java Exceptions – Complete Overview

## 1. Error (Unchecked)

| Error | Description |
|-------|-------------|
| AssertionError | assert statement failed |
| LinkageError | Problems loading classes |
| BootstrapMethodError | Error in dynamic method bootstrap |
| ClassCircularityError | Circular class dependency |
| ClassFormatError | Invalid bytecode format |
| ExceptionInInitializerError | Exception in static initializer |
| IncompatibleClassChangeError | Class changed incompatibly |
| InstantiationError | Class could not be instantiated |
| InternalError | Internal JVM error |
| NoClassDefFoundError | Class not found at runtime |
| UnsatisfiedLinkError | Required native method missing |
| VerifyError | Bytecode verification failed |
| OutOfMemoryError | JVM out of memory |
| StackOverflowError | Stack overflow |
| VirtualMachineError | General JVM error |


---

## 2. Checked Exceptions – I/O & Filesystem

| Exception | Description |
|----------|-------------|
| IOException | Generic I/O error |
| EOFException | End of file reached |
| FileNotFoundException | File not found |
| InterruptedIOException | I/O operation interrupted |
| MalformedURLException | Invalid URL |
| UnknownHostException | Host could not be resolved |
| UnknownServiceException | Unsupported service |
| ProtocolException | Error in network protocol |


---

## 3. Checked Exceptions – Reflection & Class Loading

| Exception | Description |
|----------|-------------|
| ClassNotFoundException | Class not found |
| CloneNotSupportedException | clone() not supported |
| IllegalAccessException | Access to class/member not allowed |
| InstantiationException | Class cannot be instantiated |
| InvocationTargetException | Method threw an exception |
| NoSuchFieldException | Field does not exist |
| NoSuchMethodException | Method does not exist |


---

## 4. Checked Exceptions – Concurrency / Threads

| Exception | Description |
|----------|-------------|
| ExecutionException | Exception inside Future/Thread |
| TimeoutException | Operation timed out |
| BrokenBarrierException | Barrier broken in concurrency control |
| InterruptedException | Thread was interrupted |


---

## 5. Checked Exceptions – SQL / Databases

| Exception | Description |
|----------|-------------|
| SQLException | Generic SQL error |
| SQLDataException | Invalid or incorrect SQL data |
| SQLIntegrityConstraintViolationException | Constraint violation |
| SQLInvalidAuthorizationSpecException | Authentication failure |
| SQLNonTransientConnectionException | Permanent DB connection error |
| SQLTransactionRollbackException | Transaction rolled back |


---

## 6. Checked Exceptions – Security

| Exception | Description |
|----------|-------------|
| GeneralSecurityException | Generic security error |
| InvalidKeyException | Invalid cryptographic key |
| SignatureException | Signature operation failed |
| NoSuchAlgorithmException | Algorithm does not exist |
| CertificateException | Invalid certificate |


---

## 7. Runtime Exceptions – General Programming Errors

| Exception | Description |
|----------|-------------|
| RuntimeException | Base class for all runtime exceptions |
| NullPointerException | Null reference access |
| IllegalArgumentException | Invalid argument |
| NumberFormatException | Error parsing number |
| IllegalStateException | Object in illegal state |
| IndexOutOfBoundsException | Index out of bounds |
| ArrayIndexOutOfBoundsException | Array index out of bounds |
| StringIndexOutOfBoundsException | String index out of bounds |
| ClassCastException | Type cast failed |
| UnsupportedOperationException | Operation not supported |


---

## 8. Runtime Exceptions – Collections & Data Structures

| Exception | Description |
|----------|-------------|
| ConcurrentModificationException | Concurrent modification detected |
| NoSuchElementException | Required element missing |
| DuplicateFormatFlagsException | Duplicate format flags |
| MissingResourceException | Resource not found |


---

## 9. Runtime Exceptions – Math & Arrays

| Exception | Description |
|----------|-------------|
| ArithmeticException | e.g. divide by zero |
| NegativeArraySizeException | Array cannot have negative size |


---

## 10. Runtime Exceptions – Networking

| Exception | Description |
|----------|-------------|
| UnresolvedAddressException | Address could not be resolved |
| ClosedChannelException | Channel closed |
| NotYetConnectedException | Channel not yet connected |


---

## 11. Runtime Exceptions – Reflection (Unchecked)

| Exception | Description |
|----------|-------------|
| IllegalAccessError | Illegal access detected |
| IncompatibleClassChangeError | Bytecode change incompatible |
