#Javkhlan: 30 points

def dfs(graph, start, count, visited):
    if visited[start]:
        return ["NONE", 0]

    visited[start] = True
    count += 1

    end = graph[start]
    if end == "BLUE" or end == "RED":
        return [end, count - 1]

    return dfs(graph, end, count, visited)


t = int(input())
while t:
    nr, nb, e = map(int, input().split())
    red = input().split()   # nr - 1
    blue = input().split()  # nb - 1

    graph = {}
    for i in range(2, len(red)+2):
        graph["R"+str(i)] = red[i-2]

    for i in range(2, len(blue)+2):
        graph["B"+str(i)] = blue[i-2]

    graph["B1"] = "BLUE"
    graph["R1"] = "RED"

    for i in range(e):
        event, start1, start2 = input().split()
        if event == "w":
            visited = {}
            for j in range(1, nr + 1):
                visited["R"+str(j)] = False
            for j in range(1, nb + 1):
                visited["B"+str(j)] = False

            # returns RED or BLUE with COUNT
            res1 = dfs(graph, start1, 0, visited)

            # reset all value to False
            # visited.fromkeys(visited.items(), False)
            visited = {}
            for j in range(1, nr + 1):
                visited["R"+str(j)] = False
            for j in range(1, nb + 1):
                visited["B"+str(j)] = False
            res2 = dfs(graph, start2, 0, visited)

            if res1[0] == "RED" and res2[0] == "BLUE":
                if res1[1] == res2[1]:
                    print(f"TIE {res1[1]}")
                elif res1[1] < res2[1]:
                    print(f"{res1[0]} {res1[1]}")
                else:
                    print(f"{res2[0]} {res2[1]}")
            elif res1[0] == "BLUE" and res2[0] == "RED":
                if res1[1] == res2[1]:
                    print(f"TIE {res1[1]}")
                elif res1[1] < res2[1]:
                    print(f"{res1[0]} {res1[1]}")
                else:
                    print(f"{res2[0]} {res2[1]}")
            elif res1[0] == "BLUE" and res2[0] == "NONE":
                print(f"{res1[0]} {res1[1]}")
            elif res2[0] == "BLUE" and res1[0] == "NONE":
                print(f"{res2[0]} {res2[1]}")
            elif res1[0] == "RED" and res2[0] == "NONE":
                print(f"{res1[0]} {res1[1]}")
            elif res2[0] == "RED" and res1[0] == "NONE":
                print(f"{res2[0]} {res2[1]}")
            elif res1[0] == "BLUE" and res2[0] == "BLUE":
                print(f"{res1[0]} {min(res1[1], res2[1])}")
            elif res1[0] == "RED" and res2[0] == "RED":
                print(f"{res1[0]} {min(res1[1], res2[1])}")
            elif res1[0] == "NONE" and res2[0] == "NONE":
                print(f"{res1[0]}")

        if event == "c":
            graph[start1] = start2

    t -= 1
