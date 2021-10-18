graf= {'Brebes':set (['Tegal','Slawi']),
      'Tegal':set (['Brebes', ' Pemalang', 'Slawi']),
      'Slaw1' :set (['Brebes', 'Tegal', ' Purwokerto']),
      'Purwokerto':set(['Slawi', 'Purbalingga','Kebumen','Rroya','Cilacap']),
      'Cilacap':set (['Purwokerto', 'Kroya']),
      'Kroya':set (['Cilacap', 'Purwokerto', 'Kebumen']),
      'Kebumen':set (['Rroya', 'Purwokerto', 'Purworejo']),
      'Purworejo':set (['Kebumen', 'Magelang']),
      'Magelang':set ([' Purworejo', 'Wonosobo', 'Temanggung','Bayolali']),
      'Boyolali':set(['Klaten', 'Solo','Salatiga', 'Magelang']),
      'Klaten':set (['Boyolal1']),
      'Solo':set(['SokoharJo', 'Sragen', 'Purwodadi', 'Boyolali']),
      'Sukoharjo':set(['Solo', 'Wonogiri']),
      'Wonogiri':set(['Sukoharjo']),
      'Sragen':set (['Solo','Blora']),
      'Blora':set(['Rembang', 'Sragen', 'Purwodadi']),
      'Rembang':set (['Blora', 'Kudus']),
      'Kudus ' :set (['Demak', 'Purwodadi', 'Rembang']),
      'Demak':set (['Semarang', 'Purwodadi', 'Kudus']),
      'Semarang' :set (['Demak','Salatiga', 'Kenda1']),
      'Kendal':set (['Pekalongan', 'Temanggung', ' Semarang']),
      'Pekalongan':set (['Kendal','Pemalang']),
      'Pemalang' :set ([' Pekalongan', 'Tegal', 'Purbalingga']),
      'Purbalingga' :set (['Purwokerto', 'Banjarnegara', 'Pemalang']),
      'Banjarnegara':set(['Purbalingga', 'Wonosobo']),
      'Wonosobo':set(['Banjarnegara','Magelang','Tenanggung']),
      'Temanggung' :set (['Wonosobo', 'Kendal','Salatiga', 'Magelang']),
      'Salatiga':set (['Temanggung', 'Boyolali', 'Semarang']),
      'Purwodadi':set(['Demak', 'Kudus', 'Blora','So1o']),
      
      }
print ("Menggunakan metode Breadth First Search(BFS) Gunakan cara ini--> bfs(graf,'Tegal','Semarang')")
def bfs (grat, mulai, tujuan):
    queue = [[mulai]]
    visited = set ()

    while queue: # masukkan antrian paling depan ke variabel Jalur
        jalur =queue.pop (0)
        # simpan node yang dipilih ke variabel state, misal 3alur-C,B maka simpan s
        state = jalur[-1]
        # cek state apakah sama dengan tujuan, Jika ya maka return Jalur
        if state == tujuan:
            return jalur
        # 3ika atate tidax aama dengan tujuan, maka cek apakah atate tidak ada di vi
        elif state not in visited:
        #ika state tidak ada di visited maka cek cabang
            for cabang in graf.get (state, ()):
            #cek semua cabang dari state
                jalur_baru = list(jalur)
            #masukkan isi dari variabel ialur ke variab
                jalur_baru.append(cabang)
            #update/tambah isi 1alur baru dengan cabas
                queue.append (jalur_baru)
            #tupdate/tambah queue dengan Jalur baru
            #tandai state yang sudah dikunjungi sebagai visited
            visited.add(state)
            
            #cek 1si antrian
            isi= len (queue)
            if isi == 0:
                print("Tidak ditemukan")
print ("Menggunakan metode Depth-First Search (DFS) gunakan cara ini --> dfs(graf,'Tegal','Semarang')")
def dfs (graf, mulai, tujuan):
    queue =[[mulai]]
    visited = set ()

    while queue: # masukkan antrian paling depan ke variabel Jalur
        panjang_tumpukan=len(queue)-1
        # simpan node yang dipilih ke variabel state, misal 3alur-C,B maka simpan s
        jalur = queue.pop(panjang_tumpukan)
        state=jalur[-1]
        # cek state apakah sama dengan tujuan, Jika ya maka return Jalur
        if state == tujuan:
            return jalur
        # 3ika atate tidax aama dengan tujuan, maka cek apakah atate tidak ada di vi
        elif state not in visited:
        #ika state tidak ada di visited maka cek cabang
            for cabang in graf.get (state, ()):
            #cek semua cabang dari state
                jalur_baru = list(jalur)
            #masukkan isi dari variabel ialur ke variab
                jalur_baru.append(cabang)
            #update/tambah isi 1alur baru dengan cabas
                queue.append(jalur_baru)
            #tupdate/tambah queue dengan Jalur baru
            #tandai state yang sudah dikunjungi sebagai visited
                visited.add(state)
            
            #cek 1si antrian
            isi= len (queue)
            if isi == 0:
                print("Tidak ditemukan") 
