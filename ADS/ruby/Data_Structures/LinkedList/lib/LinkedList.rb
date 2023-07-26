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

    private

    def tail(node = @head)
        return node if node.next.nil?
        tail(node.next)
    end

end

sll = SLL.new
sll.insertEnd(2)
sll.insertEnd(3)
sll.insertFront(9)
sll.insertEnd(1)
sll.insertEnd(11)
sll.printList
# puts sll.searchData(5)
# puts sll.recSearchData(11)
# puts sll.searchIndex(1)
puts sll.recSearchIndex(2)
# puts "Size of linked list is #{sll.sizeR}"
# puts "Size of linked list is #{sll.size}"