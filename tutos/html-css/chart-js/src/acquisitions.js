import zoomPlugin from 'chartjs-plugin-zoom';
import { getAcquisitionsByYear } from './api'
// import Chart from 'chart.js/auto'
// import {
//     Chart,
//     Colors,
//     BarController,
//     CategoryScale,
//     LinearScale,
//     BarElement,
//     Legend
// } from 'chart.js'
// Chart.register(
//     Colors,
//     BarController,
//     BarElement,
//     CategoryScale,
//     LinearScale,
//     Legend
// );

// lorsque parcel fait son build, il optimise la taille
// minification (courts noms de variables), tree-shaking (n'importe que les modules utilisés)
// https://parceljs.org/features/production/

(async function() {
    const data = await getAcquisitionsByYear();

    Chart.register(zoomPlugin);

    new Chart(
    document.getElementById('acquisitions'),
    {
        type: 'bar',
        data: {
        labels: data.map(row => row.year),
        datasets: [
            {
            label: 'Acquisitions by year',
            data: data.map(row => row.count)
            }
        ]
        },
        options: {
            tooltips: {
               mode: 'index'
            },  
          plugins: {
            zoom: {
                pan: {
                    enabled: true,
                },
                zoom: {
                    wheel: { // molette de souris
                    enabled: true,
                    },
                    pinch: { // trackpad
                    enabled: true
                    },
                    mode: 'xy', // on peut zoomer dans les 2 directions
                }
            }
          }
        }
    }
    );

})();


 

 