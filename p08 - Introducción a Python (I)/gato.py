def haGanado( gato ):
    contaJ1 = contaJ2 = 0
    # FILAS
    for i in range(3):
        for j in range(3):
            if gato[i][j] == 1:
                contaJ1 += 1
            elif gato[i][j] == 2:
                contaJ2 += 1
            if contaJ1 == 3:
                return True, 1
            elif contaJ2 == 3:
                return True, 2
        contaJ1 = contaJ2 = 0
    
    # COLUMNAS
    for i in range(3):
        for j in range(3):
            if gato[j][i] == 1:
                contaJ1 += 1
            elif gato[j][i] == 2:
                contaJ2 += 1
            if contaJ1 == 3:
                return True, 1
            elif contaJ2 == 3:
                return True, 2
        contaJ1 = contaJ2 = 0
    
    # DIAGONALES
    if gato[0][0] == 1 and gato[1][1] == 1 and gato[2][2] == 1:
        return True, 1
    elif gato[2][0] == 1 and gato[1][1] == 1 and gato[0][2] == 1:
        return True, 1
    elif gato[0][0] == 2 and gato[1][1] == 2 and gato[2][2] == 2:
        return True, 2
    elif gato[2][0] == 2 and gato[1][1] == 2 and gato[0][2] == 2:
        return True, 2
    else:
        return False, 0

def principal():
    cat = [ [0, 0, 0], [0, 0, 0], [0, 0, 0] ]
    jugadas = [ [ 0, 0 ], [ 0, 1 ], [ 1, 0 ], [ 1, 1 ], [ 2, 0 ] ]
    #jugadas = [ [ 0, 0 ], [ 1, 0 ], [ 0, 1 ], [ 1, 1 ], [ 0, 2 ] ]
    #jugadas = [ [ 0, 0 ], [ 1, 0 ], [ 1, 1 ], [ 1, 2 ], [ 2, 2 ] ]
    #jugadas = [ [ 0, 0 ], [ 1, 1 ], [ 1, 0 ], [ 2, 0 ], [ 0, 1 ], [ 0, 2 ] ]
    #jugadas = [ [ 0, 0 ], [ 1, 1 ], [ 1, 0 ], [ 2, 0 ], [ 0, 2 ], [ 0, 1 ], [ 2, 1 ], [ 1, 2 ], [ 2, 2 ] ]
    j1 = j2 = [0, 0]
    movimiento = 0
    ganaTermina = False
    ganador = 0
    
    while( ganaTermina == False and movimiento < 9 ):
        if( movimiento % 2 ):
            j2 = jugadas[ movimiento ]
            print("Movimiento {}, Jugador 2: {},{}".format(movimiento + 1, j2[ 0 ], j2[ 1 ] ) )
            cat[ j2[ 0 ] ][ j2[ 1 ] ] = 2
        else:
            j1 = jugadas[ movimiento ]
            print("Movimiento {}, Jugador 1: {},{}".format(movimiento + 1, j1[ 0 ], j1[ 1 ] ) )
            cat[ j1[ 0 ] ][ j1[ 1 ] ] = 1
        if movimiento > 3:
            ganaTermina, ganador = haGanado( cat )
        movimiento += 1
    if( ganaTermina ):
        print("El ganador es el Jugador {}".format( ganador ) )
    else:
        print( "No hubo ganador en esta partida" )

# Funcion inicial
principal()