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
# sll.printList
# puts "Size of linked list is #{sll.sizeR}"
# puts "Size of linked list is #{sll.size}"