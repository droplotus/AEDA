import {CGFobject} from '../lib/CGF.js';
/**
 * MyTriangle
 * @constructor
 * @param scene - Reference to MyScene object
 */
export class MyTriangleBig extends CGFobject {
	constructor(scene) {
		super(scene);
		this.initBuffers();
	}
	
	initBuffers() {
		this.vertices = [
			-1, 0, 0,	//0
			0, 0, 0,	//1
            0, 1, 0,	//2
            1, 0, 0,    //3
            -1, 1, 0,   //4
            1, 1, 0,    //5
            -2, 0, 0,   //6
            2, 0, 0,    //7
            0, 2, 0     //8
		];

		//Counter-clockwise reference of vertices
		this.indices = [
            0, 1, 2,
            1, 3, 2,
            0, 2, 4,
            3, 5, 2,
            6, 0, 4,
            3, 7, 5,
            2, 5, 8,
            4, 2, 8
		];

		//The defined indices (and corresponding vertices)
		//will be read in groups of three to draw triangles
		this.primitiveType = this.scene.gl.TRIANGLES;

		this.initGLBuffers();
	}
}

