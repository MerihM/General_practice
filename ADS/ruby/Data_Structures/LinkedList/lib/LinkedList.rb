class Node 
    attr_accessor :data, :next
    
    def initialize(data)
        @data = data
        @next = nil
    end
end

class SLL
    
    attr_accessor :head

    def initialize 
        @head = nil
    end

    def printList
        tempNode = @head
        while !tempNode.nil?
            p tempNode.data
            tempNode = tempNode.next
        end
    end
    
    def insertFront(data)
        return @head = Node.new(data) if @head.nil?
        tempNode = Node.new(data)
        tempNode.next = @head
        @head = tempNode
    end

    def insertEnd(data)
       @head.nil? ? @head = Node.new(data) : tail.next = Node.new(data)
    end

    def insertAt(data, pos)
        if pos > size + 1 || pos < 1
            puts "Error! Incorrect position"
            return
        end
        if pos == 1
            insertFront(data)
            return
        end
        if pos == size + 1
            insertEnd(data)
            return
        end
        
        newNode = Node.new(data)
        node = findNodeAtPos(pos)
        newNode.next = node.next
        node.next = newNode
    end

    def size 
        tempNode = @head
        ctr = 0
        until tempNode.nil?
            ctr += 1
            tempNode = tempNode.next
        end
        ctr
    end

    def sizeR(node = @head, ctr = 0)
        return ctr if node.nil?
        sizeR(node.next, ctr+=1)
    end

    def searchData(data)
        tempNode = @head
        ctr = 0
        until tempNode.nil?
            ctr += 1
            if tempNode.data == data
                return "Node with data #{data} is located at position #{ctr} in linked list"
            end
            tempNode = tempNode.next
        end
        "Node with data #{data} is not part of the linked list"
    end

    def recSearchData(data, node = @head, ctr = 1)
        return "Node with data #{data} is not part of the linked list" if node.nil?
        return "Node with data #{data} is located at position #{ctr} in linked list" if node.data == data
        recSearchData(data, node.next, ctr+=1)
    end

    def searchIndex(index)

        return "Incorrect index" if index > size-1 || index < 0
        ctr = 0
        tempNode = @head
        while ctr != index
            tempNode = tempNode.next
            ctr += 1
        end
        return "At index #{index} is node with data #{tempNode.data}"
    end

    def recSearchIndex(index, ctr = 0, node = @head)
        return "Incorrect index" if index > size-1 || index < 0
        return "At index #{index} is node with data #{node.data}" if index == ctr
        recSearchIndex(index, ctr += 1, node.next)
    end

    def reverseIterative
        currentNode = @head
        previousNode = nil
        while !currentNode.nil?
            nextNode = currentNode.next
            currentNode.next = previousNode
            previousNode = currentNode
            currentNode = nextNode
        end
        @head = previousNode
    end

    def reverseRec     
        @head = recHelper(@head)
    end

    def deleteVal(val)

        return puts "Value is not part of the list" if !inList?(val)
        return @head = @head.next if @head.data == val
        node = @head

        node = node.next while !node.next.nil? && node.next.data != val

        temp = node.next
        node.next = temp.next
    end

    private

    def inList? (val)
        node = @head
        while !node.nil? 
            return true if node.data == val
            node = node.next
        end
        return false
    end

    def recHelper(node)

        return node if node.nil? || node.next.nil?

        rest = recHelper(node.next)
        node.next.next = node
        node.next = nil
        return rest
    end

    def tail(node = @head)

        return node if node.next.nil?
        tail(node.next)
    end

    def findNodeAtPos(pos)

        node = @head
        ctr = 1
        while ctr < pos - 1
            node = node.next
            puts "\t#{ctr}"
            ctr += 1
        end
        return node
    end


end

sll = SLL.new
sll.insertEnd(2)
sll.insertEnd(3)
sll.insertFront(9)
sll.insertEnd(1)
sll.insertEnd(11)
# sll.printList
sll.insertAt(5, 1)
sll.printList
puts
sll.deleteVal(21)
sll.printList
# sll.reverseIterative
# puts
# sll.printList
# puts
# sll.reverseRec
# puts sll.printList
# puts sll.searchData(5)
# puts sll.recSearchData(11)
# puts sll.searchIndex(1)
# puts sll.recSearchIndex(2)
# puts "Size of linked list is #{sll.sizeR}"
# puts "Size of linked list is #{sll.size}"