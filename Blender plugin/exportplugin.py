#!BPY

"""
Name: 'OpenCraft mesh exporter'
Blender: 260
Group: 'Export'
Tooltip: 'OpenCraft mesh exporter'
"""

import Blender
import bpy

def write(path):
	sce = bpy.data.scenes.active
	ob = sce.objects.active
	mesh = ob.getData(mesh=1)
	file = open(path,"w")
	file.write("OpenCraft mesh\n")
	for face in mesh.faces:
		if (len(face.vertices) == 4):
			file.write("@beginquad@\n");
			file.write("v %f %f %f" %
			
		else:
			print "OpenCraft mesh exporter supports only quads\n"
	


Blender.Window.FileSelector(write, "Export")