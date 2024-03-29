// https://algassert.com/visualization/2014/03/27/Better-JS-Equality-Table.html
// https://jsfiddle.net/G943v/1/

var cmp = function(v1, v2) { return v1 == v2; };
var vals = [
    ["false", function() { return false; }], 
    ["0", function() { return 0; }],
    ['""', function() { return ""; }],
    ["[[]]", function() { return [[]]; }], 
    ["[]", function() { return []; }], 
    ['"0"', function() { return "0"; }], 
    ["[0]", function() { return [0]; }], 
    ["[1]", function() { return [1]; }],
    ['"1"', function() { return "1"; }],
    ["1",function() { return  1; }],
    ["true", function() { return true; }],
    ["-1", function() { return -1; }],
    ['"-1"', function() { return "-1"; }],
    ["null", function() { return null; }],
    ["undefined", function() { return undefined; }],
    ["Infinity", function() { return Infinity; }],
    ["-Infinity", function() { return -Infinity; }],
    ['"false"', function() { return "false"; }],
    ['"true"', function() { return "true"; }],
    ["{}", function() { return {}; }], 
    ["NaN", function() { return NaN; }]
];

var canvas = document.getElementById("drawCanvas");
var ctx = canvas.getContext("2d");
var n = vals.length;
var r = 20; // diameter of grid squares
var p = 60; // padding space for labels

// color grid cells
for (var i = 0; i < n; i++) {
    var v1 = vals[i][1]();
    for (var j = 0; j < n; j++) {
        var v2 = vals[j][1]();
        var eq = cmp(v1, v2);
        ctx.fillStyle = eq ? "orange" : "white";
        ctx.fillRect(p+i*r,p+j*r,r,r);
    }
}

// draw labels
ctx.fillStyle = "black";
var f = 12;
ctx.font = f + "px Helvetica";
for (var i = 0; i < n; i++) {
    var s = vals[i][0];
    var w = ctx.measureText(s).width;
    ctx.save();
    ctx.translate(p+i*r+r/2-f*0.4,p-w-2);
    ctx.rotate(3.14159/2);
    ctx.fillText(s, 0, 0);
    ctx.restore();
}
for (var i = 0; i < n; i++) {
    var s = vals[i][0];
    var w = ctx.measureText(s).width;
    ctx.fillText(s, p-w-2, p+i*r+r/2+f*0.4);
}

// draw grid lines
ctx.beginPath();
ctx.strokeStyle = "black";
for (var i = 0; i <= n; i++) {
    ctx.moveTo(p+r*i, p);
    ctx.lineTo(p+r*i, p+r*n);
    ctx.moveTo(p, p+r*i);
    ctx.lineTo(p+r*n, p+r*i);
}
ctx.stroke();
