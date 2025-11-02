# 🧩 Topic: Inter-Process Communication Using Named Pipes (FIFOs) in C

You have written two programs —

1. `writer.c` → sends a message
2. `reader.c` → receives that message

Both use a **named pipe**, which allows separate programs (even unrelated ones) to communicate.

---

## ⚙️ What Is a Named Pipe (FIFO)?

* A **named pipe** is a special file type used for **inter-process communication (IPC)**.
* Unlike normal files, data in a FIFO **isn’t stored on disk** — it exists only in memory while being transferred.
* Data written by one process can be read by another **in the order it was written** (FIFO = First In, First Out).
* Created with `mkfifo()` and accessed like a regular file using `open()`, `read()`, and `write()`.

---

# 🧱 1. Writer Program Explanation

### ✅ Code Summary

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char msg[] = "hello from the writer-lightangel26...";

    unlink("the-pipe");              // Remove old pipe if it exists
    if (mkfifo("the-pipe", 0666) == -1) {
        perror("mkfifo failed");
        exit(EXIT_FAILURE);
    }

    printf("[WRITER] Opening FIFO for writing...\n");
    fd = open("the-pipe", O_WRONLY); // Waits until a reader opens the same FIFO
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    printf("[WRITER] Writing message now...\n");
    if (write(fd, msg, sizeof(msg)) == -1) {
        perror("write failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    printf("[WRITER] Message sent successfully!\n");
    return 0;
}
```

### 🧠 Step-by-Step Explanation

| Step | Function                      | Purpose                                                                             |
| ---- | ----------------------------- | ----------------------------------------------------------------------------------- |
| 1️⃣  | `unlink("the-pipe")`          | Deletes any existing FIFO with the same name, to avoid errors.                      |
| 2️⃣  | `mkfifo("the-pipe", 0666)`    | Creates a new FIFO special file with read/write permissions for everyone.           |
| 3️⃣  | `open("the-pipe", O_WRONLY)`  | Opens the pipe for writing. This **blocks** until a reader opens the same FIFO.     |
| 4️⃣  | `write(fd, msg, sizeof(msg))` | Sends the message to the pipe. The data is stored temporarily in the kernel buffer. |
| 5️⃣  | `close(fd)`                   | Closes the writing end and signals end-of-file (EOF) to the reader.                 |

### 📄 Output Example

```
[WRITER] Opening FIFO for writing...
[WRITER] Writing message now...
[WRITER] Message sent successfully!
```

---

# 🧱 2. Reader Program Explanation

### ✅ Code Summary

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];

    printf("[READER] Opening FIFO for reading...\n");
    fd = open("the-pipe", O_RDONLY); // Waits until writer opens it for writing
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("read failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    buffer[bytesRead] = '\0'; // Null-terminate the string
    printf("[READER] Message received!\n");
    printf("          ➤ %s\n", buffer);

    close(fd);
    printf("[READER] FIFO closed, reading complete!\n");
    return 0;
}
```

### 🧠 Step-by-Step Explanation

| Step | Function                             | Purpose                                                          |
| ---- | ------------------------------------ | ---------------------------------------------------------------- |
| 1️⃣  | `open("the-pipe", O_RDONLY)`         | Opens the same FIFO for reading. Blocks until a writer connects. |
| 2️⃣  | `read(fd, buffer, sizeof(buffer)-1)` | Reads data from the pipe into the buffer.                        |
| 3️⃣  | `buffer[bytesRead] = '\0'`           | Adds a null terminator to make it a valid C string.              |
| 4️⃣  | `printf(...)`                        | Displays the received message.                                   |
| 5️⃣  | `close(fd)`                          | Closes the reading end and releases the FIFO.                    |

### 📄 Output Example

```
[READER] Opening FIFO for reading...
[READER] Message received!
          ➤ hello from the writer-lightangel26...
[READER] FIFO closed, reading complete!
```

---

# 🧠 3. How They Work Together

1. **Reader** waits for data:

   ```
   ./reader
   ```

   It blocks at `open()` until a writer connects.

2. **Writer** starts:

   ```
   ./writer
   ```

   It creates the FIFO (if not already created) and writes a message.

3. **Kernel handles communication:**

   * The message flows through the FIFO (a memory buffer managed by the OS).
   * The reader receives the data immediately once written.

4. **Both close their ends:**

   * When the writer closes, the reader sees EOF and ends.

---

# 🔒 4. Key Properties of FIFOs

| Property            | Description                                                   |
| ------------------- | ------------------------------------------------------------- |
| **Type**            | Special file type (visible in directory, not a regular file). |
| **Direction**       | One-way (unidirectional) communication by default.            |
| **Persistence**     | FIFO file persists in the filesystem until deleted manually.  |
| **Synchronization** | Both sides block until the other side opens the pipe.         |
| **Data Storage**    | Temporarily held in kernel memory, not on disk.               |

---

# ✅ 5. Summary Table

| File       | Role          | Major System Calls                           | Behavior                          |
| ---------- | ------------- | -------------------------------------------- | --------------------------------- |
| `writer.c` | Sends data    | `unlink`, `mkfifo`, `open`, `write`, `close` | Creates FIFO and writes a message |
| `reader.c` | Receives data | `open`, `read`, `close`                      | Reads message and displays it     |

---

# 💬 6. Real-Life Analogy

Think of the FIFO as a **postal dropbox**:

* The **writer** drops a letter (message) into the box.
* The **reader** opens the same box and picks up the letter.
* The postbox itself doesn’t store letters permanently — once read, it’s empty again.
