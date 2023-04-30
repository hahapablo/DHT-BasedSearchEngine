# 终端结果 只留下没过的cases

        Succ<Node 18, 10.0.22.2, 9f72e108>
Ring State
        Curr<Node 18, 10.0.22.2, 9f72e108>
        Pred<Node 10, 10.0.12.2, 9b67b1ce>
        Succ<Node 3, 10.0.3.2, ab1957d0>
End of Ring State
command == PUBLISH
fileName./contrib/upenn-cis553/keys/metadata2.keys

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Shia-LaBeouf, Transformers>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Megan-Fox, Transformers>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Elijah-Wood, Lord-of-the-Rings>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Ian-McKellen, Lord-of-the-Rings>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Orlando-Bloom, Lord-of-the-Rings>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Emilia-Clarke, Game-of-Thrones>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Kit-Harington, Game-of-Thrones>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Peter-Dinklage, Game-of-Thrones>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Johnny-Depp, Pirates-of-the-Caribbean>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Orlando-Bloom, Pirates-of-the-Caribbean>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Keira-Knightley, Pirates-of-the-Caribbean>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Chris-Evans, Avengers>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Robert-Downey-Jones, Avengers>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Chris-Hemsworth, Avengers>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Scarlet-Johansson, Avengers>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Daniel-Radcliffe, Harry-Potter>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Rupert-Grint, Harry-Potter>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Emma-Watson, Harry-Potter>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Kristen-Stewart, The-Twilight-Saga>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Robert-Pattinson, The-Twilight-Saga>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310000 ms, Message: Publish<Taylor-Lautner, The-Twilight-Saga>
txID: 970618196, term:Robert-Pattinson
txID: 970618197, term:Daniel-Radcliffe
txID: 970618198, term:Emma-Watson
txID: 970618199, term:Shia-LaBeouf
txID: 970618200, term:Megan-Fox
txID: 970618201, term:Elijah-Wood
txID: 970618202, term:Keira-Knightley
txID: 970618203, term:Orlando-Bloom
txID: 970618204, term:Kit-Harington
txID: 970618205, term:Rupert-Grint
txID: 970618206, term:Chris-Evans
txID: 970618207, term:Kristen-Stewart
txID: 970618208, term:Robert-Downey-Jones
txID: 970618209, term:Scarlet-Johansson
txID: 970618210, term:Peter-Dinklage
txID: 970618211, term:Ian-McKellen
txID: 970618212, term:Johnny-Depp
txID: 970618213, term:Taylor-Lautner
txID: 970618214, term:Emilia-Clarke
txID: 970618215, term:Chris-Hemsworth
processSearchReqPacket searchKey: 2839431881
processSearchReqPacket myKey: 2675106056
processSearchReqPacket succKey: 2870564816
processSearchReqPacket searchKey: 3317533554
processSearchReqPacket myKey: 3277935086
processSearchReqPacket succKey: 3806607131
HandleNodeLookup destAddress: 10.0.3.2, dest NodeId: 3
HandleNodeLookup txID: 970618209
store term: Scarlet-Johansson
process store keyword: Scarlet-Johansson on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 310020 ms, Message: Store<Scarlet-Johansson, Avengers>
processSearchReqPacket searchKey: 3092139357
processSearchReqPacket myKey: 2870564816
processSearchReqPacket succKey: 3244627693
processSearchReqPacket searchKey: 3020175168
processSearchReqPacket myKey: 2870564816
processSearchReqPacket succKey: 3244627693
HandleNodeLookup destAddress: 10.0.15.2, dest NodeId: 12
HandleNodeLookup txID: 970618197
store term: Daniel-Radcliffe
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 970618212
store term: Johnny-Depp
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 970618213
store term: Taylor-Lautner
processSearchReqPacket searchKey: 3828642179
processSearchReqPacket myKey: 3817320794
processSearchReqPacket succKey: 3973578366
HandleNodeLookup destAddress: 10.0.21.2, dest NodeId: 16
HandleNodeLookup txID: 970618202
store term: Keira-Knightley
process store keyword: Johnny-Depp on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 310027 ms, Message: Store<Johnny-Depp, Pirates-of-the-Caribbean>
process store keyword: Taylor-Lautner on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 310027 ms, Message: Store<Taylor-Lautner, The-Twilight-Saga>
process store keyword: Daniel-Radcliffe on nodeId: 12

*SEARCH* Node: 12, Module: PENNSEARCH, Time: 310032 ms, Message: Store<Daniel-Radcliffe, Harry-Potter>
process store keyword: Keira-Knightley on nodeId: 16

*SEARCH* Node: 16, Module: PENNSEARCH, Time: 310038 ms, Message: Store<Keira-Knightley, Pirates-of-the-Caribbean>
processSearchReqPacket searchKey: 2185360048
processSearchReqPacket myKey: 1945912260
processSearchReqPacket succKey: 2344767230
processSearchReqPacket searchKey: 2194758046
processSearchReqPacket myKey: 1945912260
processSearchReqPacket succKey: 2344767230
processSearchReqPacket searchKey: 692385726
processSearchReqPacket myKey: 468671332
processSearchReqPacket succKey: 816118083
processSearchReqPacket searchKey: 488894385
processSearchReqPacket myKey: 468671332
processSearchReqPacket succKey: 816118083
processSearchReqPacket searchKey: 1090710581
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
processSearchReqPacket searchKey: 956337114
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
processSearchReqPacket searchKey: 876423871
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
HandleNodeLookup destAddress: 10.0.11.2, dest NodeId: 9
HandleNodeLookup txID: 970618203
store term: Orlando-Bloom
HandleNodeLookup destAddress: 10.0.11.2, dest NodeId: 9
HandleNodeLookup txID: 970618204
store term: Kit-Harington
processSearchReqPacket searchKey: 1041958615
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
processSearchReqPacket searchKey: 1087985101
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
processSearchReqPacket searchKey: 910332707
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
processSearchReqPacket searchKey: 876955683
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
HandleNodeLookup destAddress: 10.0.2.2, dest NodeId: 2
HandleNodeLookup txID: 970618207
store term: Kristen-Stewart

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310124 ms, Message: Store<Kristen-Stewart, The-Twilight-Saga>
HandleNodeLookup destAddress: 10.0.2.2, dest NodeId: 2
HandleNodeLookup txID: 970618215
store term: Chris-Hemsworth

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 310125 ms, Message: Store<Chris-Hemsworth, Avengers>
processSearchReqPacket searchKey: 358966352
processSearchReqPacket myKey: 14667031
processSearchReqPacket succKey: 468671332
processSearchReqPacket searchKey: 455855284
processSearchReqPacket myKey: 14667031
processSearchReqPacket succKey: 468671332
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 970618198
store term: Emma-Watson
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 970618200
store term: Megan-Fox
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 970618201
store term: Elijah-Wood
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 970618205
store term: Rupert-Grint
process store keyword: Orlando-Bloom on nodeId: 9

*SEARCH* Node: 9, Module: PENNSEARCH, Time: 310130 ms, Message: Store<Orlando-Bloom, Lord-of-the-Rings>

*SEARCH* Node: 9, Module: PENNSEARCH, Time: 310130 ms, Message: Store<Orlando-Bloom, Pirates-of-the-Caribbean>
process store keyword: Kit-Harington on nodeId: 9

*SEARCH* Node: 9, Module: PENNSEARCH, Time: 310130 ms, Message: Store<Kit-Harington, Game-of-Thrones>
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 970618208
store term: Robert-Downey-Jones
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 970618210
store term: Peter-Dinklage
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 970618214
store term: Emilia-Clarke
HandleNodeLookup destAddress: 10.0.1.2, dest NodeId: 19
HandleNodeLookup txID: 970618196
store term: Robert-Pattinson
processSearchReqPacket searchKey: 1507587470
processSearchReqPacket myKey: 1246662886
processSearchReqPacket succKey: 1595407150
HandleNodeLookup destAddress: 10.0.1.2, dest NodeId: 19
HandleNodeLookup txID: 970618206
store term: Chris-Evans
processSearchReqPacket searchKey: 1515465379
processSearchReqPacket myKey: 1246662886
processSearchReqPacket succKey: 1595407150
process store keyword: Emma-Watson on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 310140 ms, Message: Store<Emma-Watson, Harry-Potter>
process store keyword: Megan-Fox on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 310140 ms, Message: Store<Megan-Fox, Transformers>
process store keyword: Elijah-Wood on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 310140 ms, Message: Store<Elijah-Wood, Lord-of-the-Rings>
process store keyword: Rupert-Grint on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 310141 ms, Message: Store<Rupert-Grint, Harry-Potter>
process store keyword: Robert-Downey-Jones on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 310141 ms, Message: Store<Robert-Downey-Jones, Avengers>
process store keyword: Robert-Pattinson on nodeId: 19

*SEARCH* Node: 19, Module: PENNSEARCH, Time: 310141 ms, Message: Store<Robert-Pattinson, The-Twilight-Saga>
process store keyword: Peter-Dinklage on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 310142 ms, Message: Store<Peter-Dinklage, Game-of-Thrones>
process store keyword: Emilia-Clarke on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 310142 ms, Message: Store<Emilia-Clarke, Game-of-Thrones>
process store keyword: Chris-Evans on nodeId: 19

*SEARCH* Node: 19, Module: PENNSEARCH, Time: 310143 ms, Message: Store<Chris-Evans, Avengers>
HandleNodeLookup destAddress: 10.0.14.2, dest NodeId: 11
HandleNodeLookup txID: 970618199
store term: Shia-LaBeouf
HandleNodeLookup destAddress: 10.0.14.2, dest NodeId: 11
HandleNodeLookup txID: 970618211
store term: Ian-McKellen
process store keyword: Shia-LaBeouf on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 310159 ms, Message: Store<Shia-LaBeouf, Transformers>
process store keyword: Ian-McKellen on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 310161 ms, Message: Store<Ian-McKellen, Lord-of-the-Rings>
command == PUBLISH
fileName./contrib/upenn-cis553/keys/metadata3.keys

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Russell-Crowe, A-Beautiful-Mind>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Jennifer-Connelly, A-Beautiful-Mind>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Paul-Bettany, A-Beautiful-Mind>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Brad-Pitt, Mr-Mrs-Smith>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Angelina-Jolie, Mr-Mrs-Smith>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<George-Clooney, Ocean's-Eleven>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Brad-Pitt, Ocean's-Eleven>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Matt-Damon, Ocean's-Eleven>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Don-Cheadle, Ocean's-Eleven>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Julia-Roberts, Ocean's-Eleven>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Edward-Norton, Fight-Club>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Brad-Pitt, Fight-Club>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Helena-Bonham-Carter, Fight-Club>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Mia-Wasikowska, Alice-in-Wonderland>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Johnny-Depp, Alice-in-Wonderland>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Helena-Bonham-Carter, Alice-in-Wonderland>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Tom-Hanks, Forrest-Gump>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Leonardo-DiCaprio, Titanic>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330000 ms, Message: Publish<Kate-Winslet, Titanic>
txID: 3632429424, term:Kate-Winslet
txID: 3632429425, term:Leonardo-DiCaprio
txID: 3632429426, term:Tom-Hanks
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 3632429426
store term: Tom-Hanks
txID: 3632429428, term:Russell-Crowe
txID: 3632429429, term:Paul-Bettany
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 3632429429
store term: Paul-Bettany
txID: 3632429431, term:Brad-Pitt
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 3632429431
store term: Brad-Pitt
txID: 3632429433, term:Don-Cheadle
txID: 3632429434, term:George-Clooney
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 3632429434
store term: George-Clooney
txID: 3632429436, term:Helena-Bonham-Carter
txID: 3632429437, term:Matt-Damon
txID: 3632429438, term:Julia-Roberts
txID: 3632429439, term:Angelina-Jolie
txID: 3632429440, term:Edward-Norton
txID: 3632429441, term:Jennifer-Connelly
txID: 3632429442, term:Mia-Wasikowska
txID: 3632429443, term:Johnny-Depp
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 3632429443
store term: Johnny-Depp
process store keyword: Tom-Hanks on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 330006 ms, Message: Store<Tom-Hanks, Forrest-Gump>
process store keyword: Paul-Bettany on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 330006 ms, Message: Store<Paul-Bettany, A-Beautiful-Mind>
process store keyword: Brad-Pitt on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 330007 ms, Message: Store<Brad-Pitt, Fight-Club>

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 330007 ms, Message: Store<Brad-Pitt, Mr-Mrs-Smith>

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 330007 ms, Message: Store<Brad-Pitt, Ocean's-Eleven>
process store keyword: George-Clooney on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 330007 ms, Message: Store<George-Clooney, Ocean's-Eleven>
process store keyword: Johnny-Depp on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 330008 ms, Message: Store<Johnny-Depp, Alice-in-Wonderland>
processSearchReqPacket searchKey: 2823194506
processSearchReqPacket myKey: 2675106056
processSearchReqPacket succKey: 2870564816
processSearchReqPacket searchKey: 2623799063
processSearchReqPacket myKey: 2607264206
processSearchReqPacket succKey: 2675106056
processSearchReqPacket searchKey: 2399205598
processSearchReqPacket myKey: 2362179088
processSearchReqPacket succKey: 2460931848
processSearchReqPacket searchKey: 3788022286
processSearchReqPacket myKey: 3277935086
processSearchReqPacket succKey: 3806607131
HandleNodeLookup destAddress: 10.0.15.2, dest NodeId: 12
HandleNodeLookup txID: 3632429424
store term: Kate-Winslet
HandleNodeLookup destAddress: 10.0.3.2, dest NodeId: 3
HandleNodeLookup txID: 3632429433
store term: Don-Cheadle

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 330022 ms, Message: Store<Don-Cheadle, Ocean's-Eleven>
HandleNodeLookup destAddress: 10.0.22.2, dest NodeId: 18
HandleNodeLookup txID: 3632429437
store term: Matt-Damon
HandleNodeLookup destAddress: 10.0.6.2, dest NodeId: 5
HandleNodeLookup txID: 3632429436
store term: Helena-Bonham-Carter
process store keyword: Helena-Bonham-Carter on nodeId: 5

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 330031 ms, Message: Store<Helena-Bonham-Carter, Alice-in-Wonderland>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 330031 ms, Message: Store<Helena-Bonham-Carter, Fight-Club>
process store keyword: Matt-Damon on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 330033 ms, Message: Store<Matt-Damon, Ocean's-Eleven>
process store keyword: Kate-Winslet on nodeId: 12

*SEARCH* Node: 12, Module: PENNSEARCH, Time: 330034 ms, Message: Store<Kate-Winslet, Titanic>
processSearchReqPacket searchKey: 1995095043
processSearchReqPacket myKey: 1945912260
processSearchReqPacket succKey: 2344767230
processSearchReqPacket searchKey: 1954300555
processSearchReqPacket myKey: 1945912260
processSearchReqPacket succKey: 2344767230
processSearchReqPacket searchKey: 2017310492
processSearchReqPacket myKey: 1945912260
processSearchReqPacket succKey: 2344767230
processSearchReqPacket searchKey: 858658171
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
processSearchReqPacket searchKey: 1141065726
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
HandleNodeLookup destAddress: 10.0.2.2, dest NodeId: 2
HandleNodeLookup txID: 3632429439
store term: Angelina-Jolie
HandleNodeLookup destAddress: 10.0.2.2, dest NodeId: 2
HandleNodeLookup txID: 3632429440
store term: Edward-Norton
HandleNodeLookup destAddress: 10.0.2.2, dest NodeId: 2
HandleNodeLookup txID: 3632429441
store term: Jennifer-Connelly
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 3632429425
store term: Leonardo-DiCaprio
processSearchReqPacket searchKey: 205259377
processSearchReqPacket myKey: 14667031
processSearchReqPacket succKey: 468671332
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 3632429438
store term: Julia-Roberts
process store keyword: Angelina-Jolie on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 330069 ms, Message: Store<Angelina-Jolie, Mr-Mrs-Smith>
process store keyword: Edward-Norton on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 330069 ms, Message: Store<Edward-Norton, Fight-Club>
processSearchReqPacket searchKey: 373853613
processSearchReqPacket myKey: 14667031
processSearchReqPacket succKey: 468671332
process store keyword: Jennifer-Connelly on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 330069 ms, Message: Store<Jennifer-Connelly, A-Beautiful-Mind>
HandleNodeLookup destAddress: 10.0.1.2, dest NodeId: 19
HandleNodeLookup txID: 3632429428
store term: Russell-Crowe
HandleNodeLookup destAddress: 10.0.1.2, dest NodeId: 19
HandleNodeLookup txID: 3632429442
store term: Mia-Wasikowska
process store keyword: Leonardo-DiCaprio on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 330080 ms, Message: Store<Leonardo-DiCaprio, Titanic>
process store keyword: Julia-Roberts on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 330082 ms, Message: Store<Julia-Roberts, Ocean's-Eleven>
process store keyword: Russell-Crowe on nodeId: 19

*SEARCH* Node: 19, Module: PENNSEARCH, Time: 330083 ms, Message: Store<Russell-Crowe, A-Beautiful-Mind>
process store keyword: Mia-Wasikowska on nodeId: 19

*SEARCH* Node: 19, Module: PENNSEARCH, Time: 330084 ms, Message: Store<Mia-Wasikowska, Alice-in-Wonderland>
command == PUBLISH
fileName./contrib/upenn-cis553/keys/metadata4.keys

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Leonardo-DiCaprio, Inception>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Ellen-Page, Inception>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Marion-Cotillard, Inception>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Jesse-Eisenberg, The-Social-Network>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Justin-Timberlake, The-Social-Network>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Andrew-Garfield, The-Social-Network>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Tom-Holland, Spiderman>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Andrew-Garfield, Spiderman>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Tobey-Maguire, Spiderman>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Zendaya, Spiderman>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Joaquin-Phoenix, Her>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Scarlet-Johansson, Her>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Tom-Hanks, Toy-Story>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Tim-Allen, Toy-Story>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Miles-Teller, Whiplash>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<JK-Simmons, Whiplash>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Timothee-Chalamet, Dune>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Zendaya, Dune>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Christian-Bale, The-Dark-Knight-Rises>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Tom-Hardy, The-Dark-Knight-Rises>

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350000 ms, Message: Publish<Joseph-Gordon-Levitt, The-Dark-Knight-Rises>
txID: 2850235830, term:Tom-Hardy
txID: 2850235831, term:Christian-Bale
txID: 2850235832, term:Timothee-Chalamet
txID: 2850235833, term:Joseph-Gordon-Levitt
txID: 2850235834, term:Miles-Teller
txID: 2850235835, term:Leonardo-DiCaprio
txID: 2850235836, term:Tom-Holland
txID: 2850235837, term:Ellen-Page
txID: 2850235838, term:Andrew-Garfield
txID: 2850235839, term:Tobey-Maguire
txID: 2850235840, term:Marion-Cotillard
txID: 2850235841, term:Jesse-Eisenberg
txID: 2850235842, term:Joaquin-Phoenix
txID: 2850235843, term:JK-Simmons
txID: 2850235844, term:Justin-Timberlake
txID: 2850235845, term:Scarlet-Johansson
txID: 2850235846, term:Tim-Allen
txID: 2850235847, term:Zendaya
txID: 2850235848, term:Tom-Hanks
processSearchReqPacket searchKey: 3161281289
processSearchReqPacket myKey: 2870564816
processSearchReqPacket succKey: 3244627693
processSearchReqPacket searchKey: 2917019268
processSearchReqPacket myKey: 2870564816
processSearchReqPacket succKey: 3244627693
processSearchReqPacket searchKey: 2911555914
processSearchReqPacket myKey: 2870564816
processSearchReqPacket succKey: 3244627693
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 2850235836
store term: Tom-Holland
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 2850235839
store term: Tobey-Maguire
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 2850235848
store term: Tom-Hanks
processSearchReqPacket searchKey: 2806764991
processSearchReqPacket myKey: 2675106056
processSearchReqPacket succKey: 2870564816
processSearchReqPacket searchKey: 2839431881
processSearchReqPacket myKey: 2675106056
processSearchReqPacket succKey: 2870564816
process store keyword: Tom-Holland on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 350013 ms, Message: Store<Tom-Holland, Spiderman>
process store keyword: Tobey-Maguire on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 350013 ms, Message: Store<Tobey-Maguire, Spiderman>
process store keyword: Tom-Hanks on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 350013 ms, Message: Store<Tom-Hanks, Toy-Story>
processSearchReqPacket searchKey: 4269391421
processSearchReqPacket myKey: 4215184567
processSearchReqPacket succKey: 14667031
processSearchReqPacket searchKey: 4197818138
processSearchReqPacket myKey: 4072950981
processSearchReqPacket succKey: 4215184567
HandleNodeLookup destAddress: 10.0.3.2, dest NodeId: 3
HandleNodeLookup txID: 2850235844
store term: Justin-Timberlake
HandleNodeLookup destAddress: 10.0.3.2, dest NodeId: 3
HandleNodeLookup txID: 2850235845
store term: Scarlet-Johansson
processSearchReqPacket searchKey: 4127440637
processSearchReqPacket myKey: 4072950981
processSearchReqPacket succKey: 4215184567
HandleNodeLookup destAddress: 10.0.8.2, dest NodeId: 6
HandleNodeLookup txID: 2850235843
store term: JK-Simmons
process store keyword: Justin-Timberlake on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 350027 ms, Message: Store<Justin-Timberlake, The-Social-Network>
process store keyword: Scarlet-Johansson on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 350028 ms, Message: Store<Scarlet-Johansson, Her>
process store keyword: JK-Simmons on nodeId: 6

*SEARCH* Node: 6, Module: PENNSEARCH, Time: 350030 ms, Message: Store<JK-Simmons, Whiplash>
HandleNodeLookup destAddress: 10.0.9.2, dest NodeId: 7
HandleNodeLookup txID: 2850235832
store term: Timothee-Chalamet
HandleNodeLookup destAddress: 10.0.9.2, dest NodeId: 7
HandleNodeLookup txID: 2850235842
store term: Joaquin-Phoenix
processSearchReqPacket searchKey: 2466947017
processSearchReqPacket myKey: 2460931848
processSearchReqPacket succKey: 2497211049
HandleNodeLookup destAddress: 10.0.5.2, dest NodeId: 4
HandleNodeLookup txID: 2850235830
store term: Tom-Hardy

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 350040 ms, Message: Store<Tom-Hardy, The-Dark-Knight-Rises>
process store keyword: Timothee-Chalamet on nodeId: 7

*SEARCH* Node: 7, Module: PENNSEARCH, Time: 350040 ms, Message: Store<Timothee-Chalamet, Dune>
process store keyword: Joaquin-Phoenix on nodeId: 7

*SEARCH* Node: 7, Module: PENNSEARCH, Time: 350041 ms, Message: Store<Joaquin-Phoenix, Her>
processSearchReqPacket searchKey: 2039592046
processSearchReqPacket myKey: 1945912260
processSearchReqPacket succKey: 2344767230
processSearchReqPacket searchKey: 979103130
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
processSearchReqPacket searchKey: 858658171
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
processSearchReqPacket searchKey: 879342470
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
processSearchReqPacket searchKey: 920579077
processSearchReqPacket myKey: 816118083
processSearchReqPacket succKey: 1246662886
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 2850235834
store term: Miles-Teller
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 2850235835
store term: Leonardo-DiCaprio
HandleNodeLookup destAddress: 10.0.2.2, dest NodeId: 2
HandleNodeLookup txID: 2850235837
store term: Ellen-Page
processSearchReqPacket searchKey: 1831715187
processSearchReqPacket myKey: 1595407150
processSearchReqPacket succKey: 1945912260
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 2850235846
store term: Tim-Allen
HandleNodeLookup destAddress: 10.0.23.2, dest NodeId: 17
HandleNodeLookup txID: 2850235847
store term: Zendaya
process store keyword: Ellen-Page on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 350100 ms, Message: Store<Ellen-Page, Inception>
HandleNodeLookup destAddress: 10.0.18.2, dest NodeId: 14
HandleNodeLookup txID: 2850235838
store term: Andrew-Garfield
processSearchReqPacket searchKey: 1263900830
processSearchReqPacket myKey: 1246662886
processSearchReqPacket succKey: 1595407150
processSearchReqPacket searchKey: 1308404063
processSearchReqPacket myKey: 1246662886
processSearchReqPacket succKey: 1595407150
processSearchReqPacket searchKey: 1558139766
processSearchReqPacket myKey: 1246662886
processSearchReqPacket succKey: 1595407150
processSearchReqPacket searchKey: 1260883035
processSearchReqPacket myKey: 1246662886
processSearchReqPacket succKey: 1595407150
process store keyword: Miles-Teller on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 350110 ms, Message: Store<Miles-Teller, Whiplash>
process store keyword: Leonardo-DiCaprio on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 350111 ms, Message: Store<Leonardo-DiCaprio, Inception>
process store keyword: Tim-Allen on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 350111 ms, Message: Store<Tim-Allen, Toy-Story>
process store keyword: Zendaya on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 350112 ms, Message: Store<Zendaya, Dune>

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 350112 ms, Message: Store<Zendaya, Spiderman>
process store keyword: Andrew-Garfield on nodeId: 14

*SEARCH* Node: 14, Module: PENNSEARCH, Time: 350118 ms, Message: Store<Andrew-Garfield, Spiderman>

*SEARCH* Node: 14, Module: PENNSEARCH, Time: 350118 ms, Message: Store<Andrew-Garfield, The-Social-Network>
HandleNodeLookup destAddress: 10.0.14.2, dest NodeId: 11
HandleNodeLookup txID: 2850235831
store term: Christian-Bale
HandleNodeLookup destAddress: 10.0.14.2, dest NodeId: 11
HandleNodeLookup txID: 2850235833
store term: Joseph-Gordon-Levitt
HandleNodeLookup destAddress: 10.0.14.2, dest NodeId: 11
HandleNodeLookup txID: 2850235840
store term: Marion-Cotillard
HandleNodeLookup destAddress: 10.0.14.2, dest NodeId: 11
HandleNodeLookup txID: 2850235841
store term: Jesse-Eisenberg
process store keyword: Christian-Bale on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 350129 ms, Message: Store<Christian-Bale, The-Dark-Knight-Rises>
process store keyword: Joseph-Gordon-Levitt on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 350129 ms, Message: Store<Joseph-Gordon-Levitt, The-Dark-Knight-Rises>
process store keyword: Marion-Cotillard on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 350130 ms, Message: Store<Marion-Cotillard, Inception>
process store keyword: Jesse-Eisenberg on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 350130 ms, Message: Store<Jesse-Eisenberg, The-Social-Network>
command == PUBLISH
fileName./contrib/upenn-cis553/keys/metadata5.keys

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Sandra-Bullock, Gravity>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<George-Clooney, Gravity>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Zooey-Deschanel, New-Girl>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Jake-Johnson, New-Girl>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Max-Greenfield, New-Girl>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Ralph-Fiennes, The-Grand-Budapest-Hotel>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Tony-Revolori, The-Grand-Budapest-Hotel>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Jude-Law, The-Grand-Budapest-Hotel>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Amy-Poehler, Inside-Out>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Bill-Hader, Inside-Out>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Mindy-Kaling, Inside-Out>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Tom-Hardy, Mad-Max>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Chadwick-Boseman, Black-Panther>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Michael-B-Jordan, Black-Panther>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Matthew-McConaughey, Interstellar>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Anne-Hathaway, Interstellar>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Jessica-Chastain, Interstellar>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Amy-Adams, Arrival>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Jeremy-Renner, Arrival>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Catherine-Zeta-Jones, Ocean's-Twelve>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<George-Clooney, Ocean's-Twelve>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Brad-Pitt, Ocean's-Twelve>

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370000 ms, Message: Publish<Matt-Damon, Ocean's-Twelve>
txID: 414378622, term:Matt-Damon
txID: 414378623, term:Brad-Pitt
txID: 414378624, term:Catherine-Zeta-Jones
txID: 414378625, term:Jessica-Chastain
txID: 414378626, term:Matthew-McConaughey
txID: 414378627, term:Anne-Hathaway
txID: 414378628, term:Sandra-Bullock
txID: 414378629, term:Michael-B-Jordan
txID: 414378630, term:George-Clooney
txID: 414378631, term:Jeremy-Renner
txID: 414378632, term:Mindy-Kaling
txID: 414378633, term:Max-Greenfield
txID: 414378634, term:Jake-Johnson
txID: 414378635, term:Chadwick-Boseman
txID: 414378636, term:Tony-Revolori
txID: 414378637, term:Jude-Law
txID: 414378638, term:Amy-Poehler
txID: 414378639, term:Amy-Adams
txID: 414378640, term:Zooey-Deschanel
txID: 414378641, term:Ralph-Fiennes
txID: 414378642, term:Bill-Hader
txID: 414378643, term:Tom-Hardy
HandleNodeLookup destAddress: 10.0.5.2, dest NodeId: 4
HandleNodeLookup txID: 414378643
store term: Tom-Hardy
processSearchReqPacket searchKey: 2988765376
processSearchReqPacket myKey: 2870564816
processSearchReqPacket succKey: 3244627693
process store keyword: Tom-Hardy on nodeId: 4

*SEARCH* Node: 4, Module: PENNSEARCH, Time: 370004 ms, Message: Store<Tom-Hardy, Mad-Max>
processSearchReqPacket searchKey: 3130516096
processSearchReqPacket myKey: 2870564816
processSearchReqPacket succKey: 3244627693
processSearchReqPacket searchKey: 3182526581
processSearchReqPacket myKey: 2870564816
processSearchReqPacket succKey: 3244627693
processSearchReqPacket searchKey: 2623799063
processSearchReqPacket myKey: 2607264206
processSearchReqPacket succKey: 2675106056
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 414378623
store term: Brad-Pitt
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 414378630
store term: George-Clooney
processSearchReqPacket searchKey: 2620829033
processSearchReqPacket myKey: 2607264206
processSearchReqPacket succKey: 2675106056
HandleNodeLookup destAddress: 10.0.0.1, dest NodeId: 0
HandleNodeLookup txID: 414378636
store term: Tony-Revolori
HandleNodeLookup destAddress: 10.0.22.2, dest NodeId: 18
HandleNodeLookup txID: 414378622
store term: Matt-Damon
HandleNodeLookup destAddress: 10.0.22.2, dest NodeId: 18
HandleNodeLookup txID: 414378635
store term: Chadwick-Boseman
process store keyword: Brad-Pitt on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 370019 ms, Message: Store<Brad-Pitt, Ocean's-Twelve>
process store keyword: George-Clooney on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 370020 ms, Message: Store<George-Clooney, Gravity>

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 370020 ms, Message: Store<George-Clooney, Ocean's-Twelve>
process store keyword: Tony-Revolori on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 370020 ms, Message: Store<Tony-Revolori, The-Grand-Budapest-Hotel>
processSearchReqPacket searchKey: 2860371851
processSearchReqPacket myKey: 2675106056
processSearchReqPacket succKey: 2870564816
processSearchReqPacket searchKey: 3992777588
processSearchReqPacket myKey: 3973578366
processSearchReqPacket succKey: 4072950981
processSearchReqPacket searchKey: 3527118440
processSearchReqPacket myKey: 3277935086
processSearchReqPacket succKey: 3806607131
processSearchReqPacket searchKey: 3559345921
processSearchReqPacket myKey: 3277935086
processSearchReqPacket succKey: 3806607131
processSearchReqPacket searchKey: 2711200353
processSearchReqPacket myKey: 2675106056
processSearchReqPacket succKey: 2870564816
HandleNodeLookup destAddress: 10.0.15.2, dest NodeId: 12
HandleNodeLookup txID: 414378631
store term: Jeremy-Renner
HandleNodeLookup destAddress: 10.0.15.2, dest NodeId: 12
HandleNodeLookup txID: 414378640
store term: Zooey-Deschanel
processSearchReqPacket searchKey: 4166859909
processSearchReqPacket myKey: 4072950981
processSearchReqPacket succKey: 4215184567
process store keyword: Matt-Damon on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 370032 ms, Message: Store<Matt-Damon, Ocean's-Twelve>
process store keyword: Chadwick-Boseman on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 370033 ms, Message: Store<Chadwick-Boseman, Black-Panther>
HandleNodeLookup destAddress: 10.0.3.2, dest NodeId: 3
HandleNodeLookup txID: 414378626
store term: Matthew-McConaughey
HandleNodeLookup destAddress: 10.0.3.2, dest NodeId: 3
HandleNodeLookup txID: 414378642
store term: Bill-Hader
process store keyword: Jeremy-Renner on nodeId: 12

*SEARCH* Node: 12, Module: PENNSEARCH, Time: 370039 ms, Message: Store<Jeremy-Renner, Arrival>
process store keyword: Zooey-Deschanel on nodeId: 12

*SEARCH* Node: 12, Module: PENNSEARCH, Time: 370040 ms, Message: Store<Zooey-Deschanel, New-Girl>
HandleNodeLookup destAddress: 10.0.9.2, dest NodeId: 7
HandleNodeLookup txID: 414378625
store term: Jessica-Chastain
process store keyword: Matthew-McConaughey on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 370040 ms, Message: Store<Matthew-McConaughey, Interstellar>
HandleNodeLookup destAddress: 10.0.16.2, dest NodeId: 13
HandleNodeLookup txID: 414378629
store term: Michael-B-Jordan
process store keyword: Bill-Hader on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 370042 ms, Message: Store<Bill-Hader, Inside-Out>
process store keyword: Jessica-Chastain on nodeId: 7

*SEARCH* Node: 7, Module: PENNSEARCH, Time: 370044 ms, Message: Store<Jessica-Chastain, Interstellar>
processSearchReqPacket searchKey: 2388156591
processSearchReqPacket myKey: 2362179088
processSearchReqPacket succKey: 2460931848
process store keyword: Michael-B-Jordan on nodeId: 13

*SEARCH* Node: 13, Module: PENNSEARCH, Time: 370054 ms, Message: Store<Michael-B-Jordan, Black-Panther>
HandleNodeLookup destAddress: 10.0.6.2, dest NodeId: 5
HandleNodeLookup txID: 414378639
store term: Amy-Adams

*SEARCH* Node: 5, Module: PENNSEARCH, Time: 370063 ms, Message: Store<Amy-Adams, Arrival>
processSearchReqPacket searchKey: 2306636889
processSearchReqPacket myKey: 1945912260
processSearchReqPacket succKey: 2344767230
processSearchReqPacket searchKey: 698412852
processSearchReqPacket myKey: 468671332
processSearchReqPacket succKey: 816118083
processSearchReqPacket searchKey: 485920536
processSearchReqPacket myKey: 468671332
processSearchReqPacket succKey: 816118083
processSearchReqPacket searchKey: 553960109
processSearchReqPacket myKey: 468671332
processSearchReqPacket succKey: 816118083
processSearchReqPacket searchKey: 1653495422
processSearchReqPacket myKey: 1595407150
processSearchReqPacket succKey: 1945912260
HandleNodeLookup destAddress: 10.0.11.2, dest NodeId: 9
HandleNodeLookup txID: 414378624
store term: Catherine-Zeta-Jones
HandleNodeLookup destAddress: 10.0.11.2, dest NodeId: 9
HandleNodeLookup txID: 414378634
store term: Jake-Johnson
HandleNodeLookup destAddress: 10.0.11.2, dest NodeId: 9
HandleNodeLookup txID: 414378637
store term: Jude-Law
processSearchReqPacket searchKey: 404344845
processSearchReqPacket myKey: 14667031
processSearchReqPacket succKey: 468671332
HandleNodeLookup destAddress: 10.0.2.2, dest NodeId: 2
HandleNodeLookup txID: 414378641
store term: Ralph-Fiennes
HandleNodeLookup destAddress: 10.0.1.2, dest NodeId: 19
HandleNodeLookup txID: 414378638
store term: Amy-Poehler
process store keyword: Catherine-Zeta-Jones on nodeId: 9

*SEARCH* Node: 9, Module: PENNSEARCH, Time: 370106 ms, Message: Store<Catherine-Zeta-Jones, Ocean's-Twelve>
process store keyword: Jake-Johnson on nodeId: 9

*SEARCH* Node: 9, Module: PENNSEARCH, Time: 370107 ms, Message: Store<Jake-Johnson, New-Girl>
process store keyword: Jude-Law on nodeId: 9

*SEARCH* Node: 9, Module: PENNSEARCH, Time: 370107 ms, Message: Store<Jude-Law, The-Grand-Budapest-Hotel>
process store keyword: Ralph-Fiennes on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 370108 ms, Message: Store<Ralph-Fiennes, The-Grand-Budapest-Hotel>
processSearchReqPacket searchKey: 1594205612
processSearchReqPacket myKey: 1246662886
processSearchReqPacket succKey: 1595407150
processSearchReqPacket searchKey: 1499803391
processSearchReqPacket myKey: 1246662886
processSearchReqPacket succKey: 1595407150
processSearchReqPacket searchKey: 1560714802
processSearchReqPacket myKey: 1246662886
processSearchReqPacket succKey: 1595407150
HandleNodeLookup destAddress: 10.0.18.2, dest NodeId: 14
HandleNodeLookup txID: 414378633
store term: Max-Greenfield
process store keyword: Amy-Poehler on nodeId: 19

*SEARCH* Node: 19, Module: PENNSEARCH, Time: 370116 ms, Message: Store<Amy-Poehler, Inside-Out>
process store keyword: Max-Greenfield on nodeId: 14

*SEARCH* Node: 14, Module: PENNSEARCH, Time: 370124 ms, Message: Store<Max-Greenfield, New-Girl>
HandleNodeLookup destAddress: 10.0.14.2, dest NodeId: 11
HandleNodeLookup txID: 414378627
store term: Anne-Hathaway
HandleNodeLookup destAddress: 10.0.14.2, dest NodeId: 11
HandleNodeLookup txID: 414378628
store term: Sandra-Bullock
HandleNodeLookup destAddress: 10.0.14.2, dest NodeId: 11
HandleNodeLookup txID: 414378632
store term: Mindy-Kaling
process store keyword: Anne-Hathaway on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 370136 ms, Message: Store<Anne-Hathaway, Interstellar>
process store keyword: Sandra-Bullock on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 370136 ms, Message: Store<Sandra-Bullock, Gravity>
process store keyword: Mindy-Kaling on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 370136 ms, Message: Store<Mindy-Kaling, Inside-Out>
command == SEARCH

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 390000 ms, Message: Search<Scarlet-Johansson>
viaNodeAddr: 10.0.12.2
constructInitSearchReq queryTerms size: 1
processSearchReqPacket searchKey: 2839431881
processSearchReqPacket myKey: 2675106056
processSearchReqPacket succKey: 2870564816
HandleNodeLookup destAddress: 10.0.3.2, dest NodeId: 3
HandleNodeLookup txID: 2972597698
not in destIsMe
nodeID 3's mySearchTerm: Scarlet-Johansson
docIDsSoFar: 
localResult: Avengers Her 
finalResult: Avengers Her 

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 390042 ms, Message: InvertedListShip<Scarlet-Johansson, {Avengers, Her}>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 390042 ms, Message: SearchResults<10.0.3.2, {Avengers, Her}>
command == SEARCH

*SEARCH* Node: 8, Module: PENNSEARCH, Time: 395000 ms, Message: Search<Chadwick-Boseman>
viaNodeAddr: 10.0.7.2
constructInitSearchReq queryTerms size: 1
processSearchReqPacket searchKey: 2620829033
processSearchReqPacket myKey: 2607264206
processSearchReqPacket succKey: 2675106056
HandleNodeLookup destAddress: 10.0.22.2, dest NodeId: 18
HandleNodeLookup txID: 2226690161
not in destIsMe
nodeID 18's mySearchTerm: Chadwick-Boseman
docIDsSoFar: 
localResult: Black-Panther 
finalResult: Black-Panther 

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 395053 ms, Message: InvertedListShip<Chadwick-Boseman, {Black-Panther}>

*SEARCH* Node: 8, Module: PENNSEARCH, Time: 395068 ms, Message: SearchResults<10.0.7.2, {Black-Panther}>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 460000 ms, Message: HandleNodeLeave curr term iterated: Bill-Hader

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 460000 ms, Message: HandleNodeLeave curr term iterated: Matthew-McConaughey

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 460000 ms, Message: HandleNodeLeave curr term iterated: Justin-Timberlake

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 460000 ms, Message: HandleNodeLeave curr term iterated: Don-Cheadle

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 460000 ms, Message: HandleNodeLeave curr term iterated: Scarlet-Johansson
process store keyword: Bill-Hader on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 460006 ms, Message: Store<Bill-Hader, Inside-Out>
process store keyword: Matthew-McConaughey on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 460006 ms, Message: Store<Matthew-McConaughey, Interstellar>
process store keyword: Justin-Timberlake on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 460007 ms, Message: Store<Justin-Timberlake, The-Social-Network>
process store keyword: Don-Cheadle on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 460007 ms, Message: Store<Don-Cheadle, Ocean's-Eleven>
process store keyword: Scarlet-Johansson on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 460007 ms, Message: Store<Scarlet-Johansson, Avengers>

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 460007 ms, Message: Store<Scarlet-Johansson, Her>

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Tim-Allen

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Julia-Roberts

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Leonardo-DiCaprio

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Emilia-Clarke

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Peter-Dinklage

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Robert-Downey-Jones

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Zendaya

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Rupert-Grint

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Megan-Fox

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Miles-Teller

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Elijah-Wood

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 470000 ms, Message: HandleNodeLeave curr term iterated: Emma-Watson
process store keyword: Tim-Allen on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470013 ms, Message: Store<Tim-Allen, Toy-Story>
process store keyword: Julia-Roberts on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470013 ms, Message: Store<Julia-Roberts, Ocean's-Eleven>
process store keyword: Leonardo-DiCaprio on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470013 ms, Message: Store<Leonardo-DiCaprio, Inception>

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470013 ms, Message: Store<Leonardo-DiCaprio, Titanic>
process store keyword: Emilia-Clarke on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470014 ms, Message: Store<Emilia-Clarke, Game-of-Thrones>
process store keyword: Peter-Dinklage on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470014 ms, Message: Store<Peter-Dinklage, Game-of-Thrones>
process store keyword: Robert-Downey-Jones on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470014 ms, Message: Store<Robert-Downey-Jones, Avengers>
process store keyword: Zendaya on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470014 ms, Message: Store<Zendaya, Dune>

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470014 ms, Message: Store<Zendaya, Spiderman>
process store keyword: Rupert-Grint on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470014 ms, Message: Store<Rupert-Grint, Harry-Potter>
process store keyword: Megan-Fox on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470014 ms, Message: Store<Megan-Fox, Transformers>
process store keyword: Miles-Teller on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470014 ms, Message: Store<Miles-Teller, Whiplash>
process store keyword: Elijah-Wood on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470015 ms, Message: Store<Elijah-Wood, Lord-of-the-Rings>
process store keyword: Emma-Watson on nodeId: 11

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 470015 ms, Message: Store<Emma-Watson, Harry-Potter>

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 480000 ms, Message: HandleNodeLeave curr term iterated: Ralph-Fiennes

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 480000 ms, Message: HandleNodeLeave curr term iterated: Ellen-Page

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 480000 ms, Message: HandleNodeLeave curr term iterated: Edward-Norton

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 480000 ms, Message: HandleNodeLeave curr term iterated: Angelina-Jolie

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 480000 ms, Message: HandleNodeLeave curr term iterated: Jennifer-Connelly

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 480000 ms, Message: HandleNodeLeave curr term iterated: Chris-Hemsworth

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 480000 ms, Message: HandleNodeLeave curr term iterated: Kristen-Stewart
process store keyword: Ralph-Fiennes on nodeId: 15

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 480011 ms, Message: Store<Ralph-Fiennes, The-Grand-Budapest-Hotel>
process store keyword: Ellen-Page on nodeId: 15

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 480011 ms, Message: Store<Ellen-Page, Inception>
process store keyword: Edward-Norton on nodeId: 15

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 480011 ms, Message: Store<Edward-Norton, Fight-Club>
process store keyword: Angelina-Jolie on nodeId: 15

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 480011 ms, Message: Store<Angelina-Jolie, Mr-Mrs-Smith>
process store keyword: Jennifer-Connelly on nodeId: 15

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 480011 ms, Message: Store<Jennifer-Connelly, A-Beautiful-Mind>
process store keyword: Chris-Hemsworth on nodeId: 15

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 480011 ms, Message: Store<Chris-Hemsworth, Avengers>
process store keyword: Kristen-Stewart on nodeId: 15

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 480012 ms, Message: Store<Kristen-Stewart, The-Twilight-Saga>

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 490000 ms, Message: HandleNodeLeave curr term iterated: Chadwick-Boseman

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 490000 ms, Message: HandleNodeLeave curr term iterated: Matt-Damon
process store keyword: Chadwick-Boseman on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 490004 ms, Message: Store<Chadwick-Boseman, Black-Panther>
process store keyword: Matt-Damon on nodeId: 0

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 490004 ms, Message: Store<Matt-Damon, Ocean's-Eleven>

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 490004 ms, Message: Store<Matt-Damon, Ocean's-Twelve>



Ring State
        Curr<Node 4, 10.0.5.2, 94d86aa9>
        Pred<Node 5, 10.0.6.2, 92aed708>
        Succ<Node 10, 10.0.12.2, 9b67b1ce>
Ring State
        Curr<Node 10, 10.0.12.2, 9b67b1ce>
        Pred<Node 4, 10.0.5.2, 94d86aa9>
        Succ<Node 0, 10.0.0.1, c16516ed>
Ring State
        Curr<Node 0, 10.0.0.1, c16516ed>
        Pred<Node 10, 10.0.12.2, 9b67b1ce>
        Succ<Node 8, 10.0.7.2, c36151ee>
Ring State
        Curr<Node 8, 10.0.7.2, c36151ee>
        Pred<Node 0, 10.0.0.1, c16516ed>
        Succ<Node 12, 10.0.15.2, e2e4371b>
Ring State
        Curr<Node 12, 10.0.15.2, e2e4371b>
        Pred<Node 8, 10.0.7.2, c36151ee>
        Succ<Node 1, 10.0.0.2, e387b15a>
Ring State
        Curr<Node 1, 10.0.0.2, e387b15a>
        Pred<Node 12, 10.0.15.2, e2e4371b>
        Succ<Node 16, 10.0.21.2, ecd7fe7e>
Ring State
        Curr<Node 16, 10.0.21.2, ecd7fe7e>
        Pred<Node 1, 10.0.0.2, e387b15a>
        Succ<Node 13, 10.0.16.2, f2c44cc5>
Ring State
        Curr<Node 13, 10.0.16.2, f2c44cc5>
        Pred<Node 16, 10.0.21.2, ecd7fe7e>
        Succ<Node 7, 10.0.9.2, fb3e9cb7>
Ring State
        Curr<Node 7, 10.0.9.2, fb3e9cb7>
        Pred<Node 13, 10.0.16.2, f2c44cc5>
        Succ<Node 6, 10.0.8.2, 00dfcd17>
Ring State
        Curr<Node 6, 10.0.8.2, 00dfcd17>
        Pred<Node 7, 10.0.9.2, fb3e9cb7>
        Succ<Node 19, 10.0.1.2, 1bef5b64>
Ring State
        Curr<Node 19, 10.0.1.2, 1bef5b64>
        Pred<Node 6, 10.0.8.2, 00dfcd17>
        Succ<Node 9, 10.0.11.2, 30a4f943>
Ring State
        Curr<Node 9, 10.0.11.2, 30a4f943>
        Pred<Node 19, 10.0.1.2, 1bef5b64>
        Succ<Node 11, 10.0.14.2, 5f17fb2e>
Ring State
        Curr<Node 11, 10.0.14.2, 5f17fb2e>
        Pred<Node 9, 10.0.11.2, 30a4f943>
        Succ<Node 14, 10.0.18.2, 73fc43c4>
Ring State
        Curr<Node 14, 10.0.18.2, 73fc43c4>
        Pred<Node 11, 10.0.14.2, 5f17fb2e>
        Succ<Node 15, 10.0.20.2, 8ccbfe10>
Ring State
        Curr<Node 15, 10.0.20.2, 8ccbfe10>
        Pred<Node 14, 10.0.18.2, 73fc43c4>
        Succ<Node 5, 10.0.6.2, 92aed708>
Ring State
        Curr<Node 5, 10.0.6.2, 92aed708>
        Pred<Node 15, 10.0.20.2, 8ccbfe10>
        Succ<Node 4, 10.0.5.2, 94d86aa9>
End of Ring State
command == SEARCH

*SEARCH* Node: 1, Module: PENNSEARCH, Time: 550000 ms, Message: Search<Scarlet-Johansson>
viaNodeAddr: 10.0.0.2
constructInitSearchReq queryTerms size: 1
processSearchReqPacket searchKey: 2839431881
processSearchReqPacket myKey: 2344767230
processSearchReqPacket succKey: 0
HandleNodeLookup destAddress: 102.102.102.102, dest NodeId: Unknown
HandleNodeLookup txID: 495819146
not in destIsMe
command == SEARCH

*SEARCH* Node: 8, Module: PENNSEARCH, Time: 555000 ms, Message: Search<Chadwick-Boseman>
viaNodeAddr: 10.0.7.2
constructInitSearchReq queryTerms size: 1
processSearchReqPacket searchKey: 2620829033
processSearchReqPacket myKey: 2344767230
processSearchReqPacket succKey: 0
HandleNodeLookup destAddress: 102.102.102.102, dest NodeId: Unknown
HandleNodeLookup txID: 2226690164
not in destIsMe

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Matt-Damon

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Chadwick-Boseman

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Johnny-Depp

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Don-Cheadle

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Tom-Hanks

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Bill-Hader

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Paul-Bettany

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Brad-Pitt

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Tobey-Maguire

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Matthew-McConaughey

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: George-Clooney

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Taylor-Lautner

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Tom-Holland

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Scarlet-Johansson

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Tony-Revolori

*SEARCH* Node: 0, Module: PENNSEARCH, Time: 620027 ms, Message: processNodeJoinReq curr term iterated: Justin-Timberlake
process store keyword: Matt-Damon on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620033 ms, Message: Store<Matt-Damon, Ocean's-Eleven>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620033 ms, Message: Store<Matt-Damon, Ocean's-Twelve>
process store keyword: Chadwick-Boseman on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620034 ms, Message: Store<Chadwick-Boseman, Black-Panther>
process store keyword: Johnny-Depp on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620034 ms, Message: Store<Johnny-Depp, Alice-in-Wonderland>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620034 ms, Message: Store<Johnny-Depp, Pirates-of-the-Caribbean>
process store keyword: Don-Cheadle on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620034 ms, Message: Store<Don-Cheadle, Ocean's-Eleven>
process store keyword: Tom-Hanks on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620034 ms, Message: Store<Tom-Hanks, Forrest-Gump>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620034 ms, Message: Store<Tom-Hanks, Toy-Story>
process store keyword: Bill-Hader on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620034 ms, Message: Store<Bill-Hader, Inside-Out>
process store keyword: Paul-Bettany on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620035 ms, Message: Store<Paul-Bettany, A-Beautiful-Mind>
process store keyword: Brad-Pitt on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620035 ms, Message: Store<Brad-Pitt, Fight-Club>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620035 ms, Message: Store<Brad-Pitt, Mr-Mrs-Smith>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620035 ms, Message: Store<Brad-Pitt, Ocean's-Eleven>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620035 ms, Message: Store<Brad-Pitt, Ocean's-Twelve>
process store keyword: Tobey-Maguire on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620035 ms, Message: Store<Tobey-Maguire, Spiderman>
process store keyword: Matthew-McConaughey on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620035 ms, Message: Store<Matthew-McConaughey, Interstellar>
process store keyword: George-Clooney on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620035 ms, Message: Store<George-Clooney, Gravity>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620035 ms, Message: Store<George-Clooney, Ocean's-Eleven>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620035 ms, Message: Store<George-Clooney, Ocean's-Twelve>
process store keyword: Taylor-Lautner on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620036 ms, Message: Store<Taylor-Lautner, The-Twilight-Saga>
process store keyword: Tom-Holland on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620036 ms, Message: Store<Tom-Holland, Spiderman>
process store keyword: Scarlet-Johansson on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620036 ms, Message: Store<Scarlet-Johansson, Avengers>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620036 ms, Message: Store<Scarlet-Johansson, Her>
process store keyword: Tony-Revolori on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620036 ms, Message: Store<Tony-Revolori, The-Grand-Budapest-Hotel>
process store keyword: Justin-Timberlake on nodeId: 3

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 620036 ms, Message: Store<Justin-Timberlake, The-Social-Network>

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Megan-Fox

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Robert-Downey-Jones

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Peter-Dinklage

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Emma-Watson

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Shia-LaBeouf

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Emilia-Clarke

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Ian-McKellen

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Rupert-Grint

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Leonardo-DiCaprio

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Miles-Teller

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Joseph-Gordon-Levitt

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Anne-Hathaway

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Sandra-Bullock

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Elijah-Wood

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Zendaya

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Mindy-Kaling

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Marion-Cotillard

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Jesse-Eisenberg

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Tim-Allen

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Christian-Bale

*SEARCH* Node: 11, Module: PENNSEARCH, Time: 630122 ms, Message: processNodeJoinReq curr term iterated: Julia-Roberts
process store keyword: Megan-Fox on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630135 ms, Message: Store<Megan-Fox, Transformers>
process store keyword: Robert-Downey-Jones on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630135 ms, Message: Store<Robert-Downey-Jones, Avengers>
process store keyword: Peter-Dinklage on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630135 ms, Message: Store<Peter-Dinklage, Game-of-Thrones>
process store keyword: Emma-Watson on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630135 ms, Message: Store<Emma-Watson, Harry-Potter>
process store keyword: Shia-LaBeouf on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630135 ms, Message: Store<Shia-LaBeouf, Transformers>
process store keyword: Emilia-Clarke on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630136 ms, Message: Store<Emilia-Clarke, Game-of-Thrones>
process store keyword: Ian-McKellen on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630136 ms, Message: Store<Ian-McKellen, Lord-of-the-Rings>
process store keyword: Rupert-Grint on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630136 ms, Message: Store<Rupert-Grint, Harry-Potter>
process store keyword: Leonardo-DiCaprio on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630136 ms, Message: Store<Leonardo-DiCaprio, Inception>

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630136 ms, Message: Store<Leonardo-DiCaprio, Titanic>
process store keyword: Miles-Teller on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630136 ms, Message: Store<Miles-Teller, Whiplash>
process store keyword: Joseph-Gordon-Levitt on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630137 ms, Message: Store<Joseph-Gordon-Levitt, The-Dark-Knight-Rises>
process store keyword: Anne-Hathaway on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630137 ms, Message: Store<Anne-Hathaway, Interstellar>
process store keyword: Sandra-Bullock on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630137 ms, Message: Store<Sandra-Bullock, Gravity>
process store keyword: Elijah-Wood on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630137 ms, Message: Store<Elijah-Wood, Lord-of-the-Rings>
process store keyword: Zendaya on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630137 ms, Message: Store<Zendaya, Dune>

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630137 ms, Message: Store<Zendaya, Spiderman>
process store keyword: Mindy-Kaling on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630137 ms, Message: Store<Mindy-Kaling, Inside-Out>
process store keyword: Marion-Cotillard on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630137 ms, Message: Store<Marion-Cotillard, Inception>
process store keyword: Jesse-Eisenberg on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630138 ms, Message: Store<Jesse-Eisenberg, The-Social-Network>
process store keyword: Tim-Allen on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630138 ms, Message: Store<Tim-Allen, Toy-Story>
process store keyword: Christian-Bale on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630138 ms, Message: Store<Christian-Bale, The-Dark-Knight-Rises>
process store keyword: Julia-Roberts on nodeId: 17

*SEARCH* Node: 17, Module: PENNSEARCH, Time: 630138 ms, Message: Store<Julia-Roberts, Ocean's-Eleven>

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 640096 ms, Message: processNodeJoinReq curr term iterated: Kristen-Stewart

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 640096 ms, Message: processNodeJoinReq curr term iterated: Chris-Hemsworth

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 640096 ms, Message: processNodeJoinReq curr term iterated: Jennifer-Connelly

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 640096 ms, Message: processNodeJoinReq curr term iterated: Angelina-Jolie

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 640096 ms, Message: processNodeJoinReq curr term iterated: Edward-Norton

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 640096 ms, Message: processNodeJoinReq curr term iterated: Ellen-Page

*SEARCH* Node: 15, Module: PENNSEARCH, Time: 640096 ms, Message: processNodeJoinReq curr term iterated: Ralph-Fiennes
process store keyword: Kristen-Stewart on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 640107 ms, Message: Store<Kristen-Stewart, The-Twilight-Saga>
process store keyword: Chris-Hemsworth on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 640107 ms, Message: Store<Chris-Hemsworth, Avengers>
process store keyword: Jennifer-Connelly on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 640108 ms, Message: Store<Jennifer-Connelly, A-Beautiful-Mind>
process store keyword: Angelina-Jolie on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 640108 ms, Message: Store<Angelina-Jolie, Mr-Mrs-Smith>
process store keyword: Edward-Norton on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 640108 ms, Message: Store<Edward-Norton, Fight-Club>
process store keyword: Ellen-Page on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 640108 ms, Message: Store<Ellen-Page, Inception>
process store keyword: Ralph-Fiennes on nodeId: 2

*SEARCH* Node: 2, Module: PENNSEARCH, Time: 640108 ms, Message: Store<Ralph-Fiennes, The-Grand-Budapest-Hotel>



*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Tom-Holland

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Taylor-Lautner

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Johnny-Depp

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Don-Cheadle

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Tony-Revolori

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Scarlet-Johansson

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Justin-Timberlake

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Matthew-McConaughey

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Chadwick-Boseman

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Brad-Pitt

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Tobey-Maguire

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Bill-Hader

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Tom-Hanks

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Matt-Damon

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: Paul-Bettany

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 650046 ms, Message: processNodeJoinReq curr term iterated: George-Clooney
process store keyword: Tom-Holland on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650057 ms, Message: Store<Tom-Holland, Spiderman>
process store keyword: Taylor-Lautner on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650057 ms, Message: Store<Taylor-Lautner, The-Twilight-Saga>
process store keyword: Johnny-Depp on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650057 ms, Message: Store<Johnny-Depp, Alice-in-Wonderland>

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650057 ms, Message: Store<Johnny-Depp, Pirates-of-the-Caribbean>
process store keyword: Don-Cheadle on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650058 ms, Message: Store<Don-Cheadle, Ocean's-Eleven>
process store keyword: Tony-Revolori on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650058 ms, Message: Store<Tony-Revolori, The-Grand-Budapest-Hotel>
process store keyword: Scarlet-Johansson on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650058 ms, Message: Store<Scarlet-Johansson, Avengers>

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650058 ms, Message: Store<Scarlet-Johansson, Her>
process store keyword: Justin-Timberlake on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650058 ms, Message: Store<Justin-Timberlake, The-Social-Network>
process store keyword: Matthew-McConaughey on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650058 ms, Message: Store<Matthew-McConaughey, Interstellar>
process store keyword: Chadwick-Boseman on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650058 ms, Message: Store<Chadwick-Boseman, Black-Panther>
process store keyword: Brad-Pitt on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Brad-Pitt, Fight-Club>

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Brad-Pitt, Mr-Mrs-Smith>

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Brad-Pitt, Ocean's-Eleven>

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Brad-Pitt, Ocean's-Twelve>
process store keyword: Tobey-Maguire on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Tobey-Maguire, Spiderman>
process store keyword: Bill-Hader on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Bill-Hader, Inside-Out>
process store keyword: Tom-Hanks on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Tom-Hanks, Forrest-Gump>

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Tom-Hanks, Toy-Story>
process store keyword: Matt-Damon on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Matt-Damon, Ocean's-Eleven>

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Matt-Damon, Ocean's-Twelve>
process store keyword: Paul-Bettany on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650059 ms, Message: Store<Paul-Bettany, A-Beautiful-Mind>
process store keyword: George-Clooney on nodeId: 18

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650060 ms, Message: Store<George-Clooney, Gravity>

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650060 ms, Message: Store<George-Clooney, Ocean's-Eleven>

*SEARCH* Node: 18, Module: PENNSEARCH, Time: 650060 ms, Message: Store<George-Clooney, Ocean's-Twelve>
Ring State
        Curr<Node 3, 10.0.3.2, ab1957d0>
        Pred<Node 18, 10.0.22.2, 9f72e108>
        Succ<Node 0, 10.0.0.1, c16516ed>
Ring State
        Curr<Node 0, 10.0.0.1, c16516ed>
        Pred<Node 3, 10.0.3.2, ab1957d0>
        Succ<Node 8, 10.0.7.2, c36151ee>
Ring State
        Curr<Node 8, 10.0.7.2, c36151ee>
        Pred<Node 0, 10.0.0.1, c16516ed>
        Succ<Node 12, 10.0.15.2, e2e4371b>
Ring State
        Curr<Node 12, 10.0.15.2, e2e4371b>
        Pred<Node 8, 10.0.7.2, c36151ee>
        Succ<Node 1, 10.0.0.2, e387b15a>
Ring State
        Curr<Node 1, 10.0.0.2, e387b15a>
        Pred<Node 12, 10.0.15.2, e2e4371b>
        Succ<Node 16, 10.0.21.2, ecd7fe7e>
Ring State
        Curr<Node 16, 10.0.21.2, ecd7fe7e>
        Pred<Node 1, 10.0.0.2, e387b15a>
        Succ<Node 13, 10.0.16.2, f2c44cc5>
Ring State
        Curr<Node 13, 10.0.16.2, f2c44cc5>
        Pred<Node 16, 10.0.21.2, ecd7fe7e>
        Succ<Node 7, 10.0.9.2, fb3e9cb7>
Ring State
        Curr<Node 7, 10.0.9.2, fb3e9cb7>
        Pred<Node 13, 10.0.16.2, f2c44cc5>
        Succ<Node 6, 10.0.8.2, 00dfcd17>
Ring State
        Curr<Node 6, 10.0.8.2, 00dfcd17>
        Pred<Node 7, 10.0.9.2, fb3e9cb7>
        Succ<Node 19, 10.0.1.2, 1bef5b64>
Ring State
        Curr<Node 19, 10.0.1.2, 1bef5b64>
        Pred<Node 6, 10.0.8.2, 00dfcd17>
        Succ<Node 9, 10.0.11.2, 30a4f943>
Ring State
        Curr<Node 9, 10.0.11.2, 30a4f943>
        Pred<Node 19, 10.0.1.2, 1bef5b64>
        Succ<Node 17, 10.0.23.2, 4a4e90e6>
Ring State
        Curr<Node 17, 10.0.23.2, 4a4e90e6>
        Pred<Node 9, 10.0.11.2, 30a4f943>
        Succ<Node 11, 10.0.14.2, 5f17fb2e>
Ring State
        Curr<Node 11, 10.0.14.2, 5f17fb2e>
        Pred<Node 17, 10.0.23.2, 4a4e90e6>
        Succ<Node 14, 10.0.18.2, 73fc43c4>
Ring State
        Curr<Node 14, 10.0.18.2, 73fc43c4>
        Pred<Node 11, 10.0.14.2, 5f17fb2e>
        Succ<Node 2, 10.0.2.2, 8bc24efe>
Ring State
        Curr<Node 2, 10.0.2.2, 8bc24efe>
        Pred<Node 14, 10.0.18.2, 73fc43c4>
        Succ<Node 15, 10.0.20.2, 8ccbfe10>
Ring State
        Curr<Node 15, 10.0.20.2, 8ccbfe10>
        Pred<Node 2, 10.0.2.2, 8bc24efe>
        Succ<Node 5, 10.0.6.2, 92aed708>
Ring State
        Curr<Node 5, 10.0.6.2, 92aed708>
        Pred<Node 15, 10.0.20.2, 8ccbfe10>
        Succ<Node 4, 10.0.5.2, 94d86aa9>
Ring State
        Curr<Node 4, 10.0.5.2, 94d86aa9>
        Pred<Node 5, 10.0.6.2, 92aed708>
        Succ<Node 10, 10.0.12.2, 9b67b1ce>
Ring State
        Curr<Node 10, 10.0.12.2, 9b67b1ce>
        Pred<Node 4, 10.0.5.2, 94d86aa9>
        Succ<Node 18, 10.0.22.2, 9f72e108>
Ring State
        Curr<Node 18, 10.0.22.2, 9f72e108>
        Pred<Node 10, 10.0.12.2, 9b67b1ce>
        Succ<Node 3, 10.0.3.2, ab1957d0>
End of Ring State

command == SEARCH

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 710000 ms, Message: Search<Scarlet-Johansson>
viaNodeAddr: 10.0.12.2
constructInitSearchReq queryTerms size: 1
processSearchReqPacket searchKey: 2839431881
processSearchReqPacket myKey: 2675106056
processSearchReqPacket succKey: 2870564816
HandleNodeLookup destAddress: 10.0.3.2, dest NodeId: 3
HandleNodeLookup txID: 2972597700
not in destIsMe
nodeID 3's mySearchTerm: Scarlet-Johansson
docIDsSoFar: 
localResult: Avengers Her 
finalResult: Avengers Her 

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 710042 ms, Message: InvertedListShip<Scarlet-Johansson, {Avengers, Her}>

*SEARCH* Node: 3, Module: PENNSEARCH, Time: 710042 ms, Message: SearchResults<10.0.3.2, {Avengers, Her}>


End of Simulation.
AvgHopCount<0, 0, 0>
AvgHopCount<1, 1, 1>
AvgHopCount<2, 20, 20>
AvgHopCount<3, 16, 16>
AvgHopCount<4, 19, 19>
AvgHopCount<5, 22, 22>
AvgHopCount<6, 0, 0>
AvgHopCount<7, 0, 0>
AvgHopCount<8, 2, 2>
AvgHopCount<9, 0, 0>
AvgHopCount<10, 2, 2>
AvgHopCount<11, 0, 0>
AvgHopCount<12, 0, 0>
AvgHopCount<13, 0, 0>
AvgHopCount<14, 0, 0>
AvgHopCount<15, 0, 0>
AvgHopCount<16, 0, 0>
AvgHopCount<17, 0, 0>
AvgHopCount<18, 0, 0>
AvgHopCount<19, 0, 0>
AvgHopCount<20, 0, 0>
AvgHopCount<21, 0, 0>
AvgHopCount<22, 0, 0>
AvgHopCount<23, 0, 0>
AvgHopCount<24, 0, 0>
AvgHopCount<25, 0, 0>
AvgHopCount<26, 0, 0>
AvgHopCount<27, 0, 0>
AvgHopCount<28, 0, 0>
AvgHopCount<29, 0, 0>
cis553@00c1f1a60ea9:~$ 
