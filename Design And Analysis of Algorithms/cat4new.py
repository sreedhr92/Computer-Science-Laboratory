def merge_outlines1(u, v):
    i = 0
    j = 0
    w = []
    ##least x coordinate takes the preference for the outline
    while i < len(u) and j < len(v):
        if u[i][0] < v[j][0]:
            corner = (u[i][0], u[i][1])
            i += 1
        else:
            corner = (v[j][0], v[j][1])
            j += 1
        w.append(corner)
    ## merging the left item items in the list u,v
    while i < len(u):
        corner = (u[i][0], u[i][1])
        w.append(corner)
        i += 1
    while j < len(v):
        corner = (v[j][0], v[j][1])
        w.append(corner)
        j += 1
    return w


def merge_outlines2(u, v):
    i = 0
    j = 0
    w = []
    h1 = 0
    h2 = 0
    ##least x coordinate takes the preference for the outline
    ##max of the height takes the prefernce
    while (i < len(u) and j < len(v)):
        if u[i][0] < v[j][0]:
            h1 = u[i][1]
            corner = (u[i][0], max(h1, h2))
            i += 1
        else:
            h2 = v[j][1]
            corner = (v[j][0], max(h1, h2))
            j += 1
        w.append(corner)
    ## merging the left item items in the list u,v
    while (i < len(u)):
        corner = (u[i][0], u[i][1])
        w.append(corner)
        i += 1
    while (j < len(v)):
        corner = (v[j][0], v[j][1])
        w.append(corner)
        j += 1
    return w


def merge_outlines3(u, v):
    i = 0
    j = 0
    w = []
    h1 = 0
    h2 = 0
    ##least x coordinate takes the preference for the outline
    ##max of the height takes the prefernce
    ##now removing the redutant height
    count = 0
    while (i < len(u) and j < len(v)):
        if u[i][0] < v[j][0]:
            h1 = u[i][1]
            y = max(h1, h2)
            corner = (u[i][0], y)
            i += 1
        else:
            h2 = v[j][1]
            y = max(h1, h2)
            corner = (v[j][0], y)
            j += 1
        if count == 0:
            w.append(corner)
            prev_height = y
            count += 1
        if y == prev_height:
            continue
        else:
            w.append(corner)
            prev_height = y
            count += 1
    ## merging the left item items in the list u,v
    while (i < len(u)):
        corner = (u[i][0], u[i][1])
        w.append(corner)
        i += 1
    while (j < len(v)):
        corner = (v[j][0], v[j][1])
        w.append(corner)
        j += 1
    return w


def construct_outline(rs):
    if len(rs) == 1:
        return rs[0]
    if len(rs) == 0:
        return []
    a = construct_outline(rs[:len(rs) // 2])
    b = construct_outline(rs[len(rs) // 2:])
    return merge_outlines3(a, b)


u = [(1, 0), (3, 11), (9, 13), (12, 0), (16, 7)]
v = [(14, 0), (19, 3), (22, 18), (23, 3), (29, 13)]

rs = [[(1, 0), (5, 11)], [(2, 0), (7, 6)], [(3, 0), (9, 13)], [(12, 0), (16, 7)],
      [(14, 0), (25, 3)], [(19, 0), (22, 18)], [(23, 0), (29, 13)], [(24, 0), (28, 4)]]

print(merge_outlines1(u, v))
print(merge_outlines2(u, v))
print(merge_outlines3(u, v))
print(construct_outline(rs))