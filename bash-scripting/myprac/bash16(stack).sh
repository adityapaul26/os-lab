r!/usr/bin/bash

stack=()
top=-1
MAX=5

push() {
    if ((top == MAX - 1)); then
        echo "Stack Overflow"
        return
    fi

    echo -n "Enter element to push: "
    read item

    ((top++))
    stack[$top]=$item
    echo "Pushed: $item"
}

pop() {
    if ((top == -1)); then
        echo "Stack Underflow"
        return
    fi

    echo "Popped element: ${stack[$top]}"
    unset stack[$top]
    ((top--))
}

peek() {
    if ((top == -1)); then
        echo "Stack is empty"
    else
        echo "Top element: ${stack[$top]}"
    fi
}

display() {
    if ((top == -1)); then
        echo "Stack is empty"
        return
    fi

    echo "Stack elements:"
    for ((i = top; i >= 0; i--)); do
        echo "${stack[$i]}"
    done
}

# Menu-driven program
while true; do
    echo
    echo "1. Push"
    echo "2. Pop"
    echo "3. Peek"
    echo "4. Display"
    echo "5. Exit"
    echo -n "Enter choice: "
    read choice

    case $choice in
    1) push ;;
    2) pop ;;
    3) peek ;;
    4) display ;;
    5) exit ;;
    *) echo "Invalid choice" ;;
    esac
done
