#!/usr/bin/python
# -*- coding: utf-8 -*-

'''

Nombre: rdnewline (Remove Double Newline)
Versión: 0.1
Autor: BoscoverySAT - @codexlynx
Fecha: 27/10/15
Licencia: Creative Commons Share-Alike 3.0

Descripción:

    Script básico creado para solventar un pequeño problema,
    encontrado durante el proceso testeo de algunos sensores.
    Su función es el eliminado de dobles salto de líneas
    en un archivo de texto plano (txt, csv, etc).

'''

import sys

class rdnewline(object):

    def __init__(self):
        if len(sys.argv) < 2:
            self.help()
        else:
            self.filename = sys.argv[1]

    def help(self):
        print 'rdnewline - Remove Double Newline | BoscoverySAT/@codelynx'
        print ''
        print '     Usage: ' + sys.argv[0] + ' <filename>'
        print ''
        sys.exit(1)

    def remove(self):
        opener = open(self.filename, 'r')
        content = opener.read()
        opener.close()

        new = content.replace('\n\n', '\n')
        print new

        opener = open(self.filename, 'w')
        opener.write(new)
        opener.close()

if __name__ == '__main__':
    rdn = rdnewline()
    rdn.remove()
