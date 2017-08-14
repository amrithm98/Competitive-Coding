def build_cost(base,h):
    total_cost=0
    for i in range(h):
        total_cost+=(max(base-i,1)**2)
    total_cost*=1000
    return total_cost

q=input()
for i in range(q):
    n,base=map(int,raw_input().split())
    heights=map(int,raw_input().split())
    size=len(heights)
    l=len(heights)
    if(size%2!=0):
        max_element=max(heights)
        max_index=heights.index(max_element)
        mid_element=heights[(l/2)+1]
        #An IF WS HERE
        index_diff=abs(max_index-(size/2)+1)
        if(abs(max_element-mid_element)>index_diff):
            #Same Mid Element
            l_half=heights[l/2:]
            r_half=heights[:l/2]
            req_lhalf=[x for x in range(max_element-(l/2),max_element)]
            # req_rhalf=[x for x in range(max_element+1,(l/2)+max_element+1)]
            req_rhalf=[]
            for e in range(len(req_lhalf)-1,-1,-1):
                req_rhalf+=[req_lhalf[e]]
            exp_list=req_lhalf+[max_element]+req_rhalf
            diff_list=[a_i - b_i for a_i, b_i in zip(exp_list, heights)]
            tcost=0
            for i in diff_list:
                tcost+=build_cost(base,i)   
            print(tcost)     
        else:
            max_element+=index_diff
            l_half=heights[l/2:]
            r_half=heights[:l/2]
            req_lhalf=[x for x in range(max_element-(l/2),max_element)]
            # req_rhalf=[x for x in range(max_element+1,(l/2)+max_element+1)]
            req_rhalf=[]
            for e in range(len(req_lhalf)-1,-1,-1):
                req_rhalf+=[req_lhalf[e]]
            exp_list=req_lhalf+[max_element]+req_rhalf
            diff_list=[a_i - b_i for a_i, b_i in zip(exp_list, heights)]
            tcost=0
            for i in diff_list:
                tcost+=build_cost(base,i)   
            print(tcost) 
    else:
        max_element=max(heights)
        max_index=heights.index(max_element)
        mid_elements=[heights[l/2],heights[(l/2)+1]]
        index_diff=abs(max_index-(size/2)+1)
        if(abs(max_element-max(mid_elements))>index_diff):
            #Same Mid Element
            l_half=heights[l/2:]
            r_half=heights[:l/2]
            req_lhalf=[x for x in range(max_element-(l/2)+1,max_element)]
            # req_rhalf=[x for x in range(max_element+1,(l/2)+max_element+1)]
            req_rhalf=[]
            for e in range(len(req_lhalf)-1,-1,-1):
                req_rhalf+=[req_lhalf[e]]
            exp_list=req_lhalf+[max_element]*2+req_rhalf
            diff_list=[a_i - b_i for a_i, b_i in zip(exp_list, heights)]
            tcost=0
            for i in diff_list:
                tcost+=build_cost(base,i)   
            print(tcost)     
        else:
            max_element+=index_diff
            l_half=heights[l/2:]
            r_half=heights[:l/2]
            req_lhalf=[x for x in range(max_element-(l/2)+1,max_element)]
            # req_rhalf=[x for x in range(max_element+1,(l/2)+max_element+1)]
            req_rhalf=[]
            for e in range(len(req_lhalf)-1,-1,-1):
                req_rhalf+=[req_lhalf[e]]
            exp_list=req_lhalf+[max_element]*2+req_rhalf
            diff_list=[a_i - b_i for a_i, b_i in zip(exp_list, heights)]
            tcost=0
            for i in diff_list:
                tcost+=build_cost(base,i)   
            print(tcost)  

                