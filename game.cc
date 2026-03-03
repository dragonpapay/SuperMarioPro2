#include "game.hh"
using namespace pro2;
using namespace std;


/*****************************************************************
 * Constructora Game
 *****************************************************************/
Game::Game(int width, int height)
    : mario_({width / 2, 150}),
      bowser_({2800,  height -36}),
      //Posicions corresponents a totes les platforms de game
      platforms_{
        Platform(-100, -84,238 ,height-32),

        Platform(300, 400, 230, 241),
        Platform(500, 630, 230, 241),

        Platform(850, 866 ,268, 284),
        Platform(866,882, 252, 284 ),
        Platform(882, 898, 236, 284),
        Platform(898, 919, 220, 284),

        Platform(1032, 1048, 273, 284),
        
        Platform(1250, 1280, 230, 284),

        Platform(1700, 1748, 268, 284),
        Platform(1716, 1748, 252, 268),
        Platform(1732, 1748, 236, 252),
        Platform(1796, 1924, 236, 252),

        Platform(1960, 2060,204 ,220),

        Platform(1960, 1976, 268, 284),
        Platform(2120, 2136, 268, 284),
        
        //cruz
        Platform(2250, 2266, 220, 284),
        Platform(2234, 2282, 236, 247),

        Platform(2340, 2356, 220, 284),
        Platform(2324, 2372, 236, 247),
        
        //Bowser combat
        Platform(2480, 2520, 105, 123),
        Platform(2500, 3250, 89, 105),
        Platform(3234, 3250, 105, 284),

        Platform(2460, 2520, 273,284),

        Platform(2600, 2680, 240, 251),     
        Platform(2700, 2780, 210, 221),  
        Platform(2850, 2930, 180, 191), 
        Platform(3000, 3080, 226, 237),  

      },
      
      Floppys_{ 
            
            Floppy({510, 220}, VERTICAL), 
            Floppy({480, 210}, WAVE),
            Floppy ({550, 260}, HORIZONTAL),
            Floppy({620,225}, HORIZONTAL),
            Floppy({910, 205}, STATIC),    

            Floppy({1200, 235}, HORIZONTAL),
            Floppy({1265, 220},VERTICAL),
            

            Floppy({1470, 278}, STATIC),
            Floppy({1500, 278}, STATIC),
            Floppy({1530, 278}, STATIC),
            Floppy({1560, 278}, STATIC),

            Floppy({1665, 270}, HORIZONTAL),
            Floppy({1740, 225}, VERTICAL),

            Floppy({1820, 225}, HORIZONTAL),
            Floppy({1870, 225}, HORIZONTAL),


            Floppy({2640, 235}, STATIC),
            Floppy({2740, 200}, STATIC),
            Floppy({3040, 205}, STATIC),


            },

            
        
     Cds_{
        Cd({350, 220}, STATIC_C),
        Cd({2000, 190}, STATIC_C),

        Cd({2890, 175}, STATIC_C)
            
     },
     Androids_{
        Android({500, height -36}),
        Android({1200, height -36}),
        Android({2000, height - 36}),
        Android({2290, height - 36}),

        
          
     },
     
        cfloor_{
            (Circuitfloor(-1000, (320*3) -41 , height - 36, height)),
            (Circuitfloor(1010, 1376 ,height - 36, height)),

            (Circuitfloor(1430, 1580, height - 36, height)),
            
            (Circuitfloor(1640, 1748,height - 36, height)),
            (Circuitfloor(1940, 2150, height - 36, height)),

            (Circuitfloor(2200, 2410, height - 36, height)),
            
            (Circuitfloor(2480, 3250, height - 36, height)),


        },

        finished_(false), counter_(0), state_(PLAYING) {

    /** add de tots els finders */
    for(Platform& platform: platforms_){
        finder_platrform_.add(&platform);
    }
    for(Floppy& floppy: Floppys_){
        finder_floppy_.add(&floppy);
    }
    
    
    for(Circuitfloor& cf: cfloor_){
        finder_cfloor_.add(&cf);
    } 
      
    for(Cd& cd: Cds_){
        finder_cd_.add(&cd);
    }
    for (Android& androdid: Androids_){
        finder_android_.add(&androdid);
    }
    
    for(Spark& s: bowser_.get_sparks()){
        finder_sparks_.add(&s);
    }
    
    finder_bowser_.add(&bowser_);    
   
}



void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(Keys::Escape)) {
        finished_ = true;
        return;
    }
    if( window.was_key_pressed('P')) {
        if(state_ != PAUSED) state_ = PAUSED;
        else if(state_ == PAUSED) state_ = PLAYING;
    }
 
}

/***************************************************
 * UPDATE OBJ INDIVIDUALS
 **************************************************/


void Game::update_floppy(pro2::Window& window, const std::set<Floppy*>& vis_floppys){
    // Actualitza i comprova colisió entre Mario i Floppys.
    // Si hi ha colisió, elimina el Floppy i incrementa contador.
    set<Floppy*>::iterator itfs = vis_floppys.begin();
    while(itfs != vis_floppys.end()){
        (*itfs)->update(window);
        finder_floppy_.update((*itfs));
        
        bool colision = rect_touch(mario_.get_rect(),(*itfs)->get_rect());
        if(colision) {
            finder_floppy_.remove((*itfs));
            ++counter_;
            ++itfs;
        }
        else ++itfs;

        
    }
}

void Game::update_cds(pro2::Window& window, const std::set<Cd*>& vis_cds){
     // Actualitza i comprova col·lisió entre Mario i Cds.
    // Si hi ha col·lisió, elimina el cd i Mario es big si no ho era.
    set<Cd*>::iterator itcs = vis_cds.begin();
    while (itcs != vis_cds.end()){
        (*itcs)->update(window);
        finder_cd_.update(*itcs);
        
        bool colision = rect_touch(mario_.get_rect(),(*itcs)->get_rect());
        
        if(colision) {
            finder_cd_.remove((*itcs));
            mario_.toggle_state(BIG);
            cout << mario_.is_big() << endl;
            ++itcs;
        }
        else ++itcs;
    }
}

void Game::update_androids(pro2::Window& window,std::set<Android*>& vis_androids,
            const std::set<Platform*>& vis_platforms, const std::set<Circuitfloor*>& vis_cfloor ){
     // Actualitza Androids i comprova col·lisió amb Mario.
    // Si Mario mata Android, l'elimina.
    // Si Mario es petit es cambia el state de game si no mario es petit
    set<Android*>::iterator itas = vis_androids.begin();
    while (itas != vis_androids.end()){
        (*itas)->update(window, vis_platforms, vis_cfloor);
        finder_android_.update(*itas);

        bool colision = rect_touch(mario_.get_rect(), (*itas)->get_rect());
        
        if(colision){
            if(mario_.kill((*itas))){
                (*itas)->set_killed(true);
                (*itas)->paint(window);
                Android* to_remove = *itas;          
                finder_android_.remove(to_remove);  
                itas = vis_androids.erase(itas);
            }

            else if(not mario_.is_immortal()){
                if(mario_.is_big()) {
                    mario_.toggle_state(SMALL);

                }
                else {
                    state_ = WASTED; 
                }
                ++itas;
                
            }
            
        }
        else ++itas;
                
    }
}

void Game::update_bowser(pro2::Window& window,std::set<Bowser*>& vis_bowser_ ,std::set<Platform*>& vis_platforms, 
     std::set<Circuitfloor*>& vis_cfloor, const pro2::Rect& mario_rect){
        // Actualitza Bowser, dispara espurnes periòdicament.
        // Si Bowser col·lisiona amb Mario o és matat, canvia estat joc.
    for(Bowser* b : vis_bowser_){
        bool colision = rect_touch(b->get_rect(), mario_rect);
        
        if(b->bowser_state() == ALIVE){
            if (window.frame_count() % 64 == 0 ) { 
                
                b->launch_spark(mario_rect);
            }
            bool mkilled;
            b->update(window, vis_platforms, vis_cfloor, mario_rect,mkilled);   
            if(colision or mkilled){
                if(mario_.killb((*b))){
                    b->toggle_state(DEAD);
                    state_ = WINED;
                }
                else if(not mario_.is_immortal()){
                    mario_.set_immortal();
                    if(mario_.is_big()) {
                        mario_.toggle_state(SMALL);
    
                    }
                    else state_ = WASTED;
                }
            }
    
        }

    }
    
}
void Game::update_sparks(pro2::Window& window,const std::set<Spark*>& vis_sparks , Mario& mario_){
    //Actulitza Sparks
    //Si Spark colisiona amb mario i es petit cambia el estat del joc si no mario es petit
    set<Spark*>::iterator its = vis_sparks.begin();
    while (its != vis_sparks.end()){
        
        (*its)->update(window);

        finder_sparks_.update(*its);

        bool colision = rect_touch(mario_.get_rect(), (*its)->get_rect());

        if(colision){
            
            if(not mario_.is_immortal()){
                if(mario_.is_big()) {
                    mario_.toggle_state(SMALL);
                }
                else {
                    state_ = WASTED;
                }
                ++its;
            }
            
        }
        else ++its;
                
    }

}


/***************************************************
 * UPDATE OBJ GENERAL
 **************************************************/

void Game::update_objects(pro2::Window& window) {
    const Pt cam = window.camera_center();
    pro2::Rect camrect = window.camera_rect();
    pro2::Rect mario_rect = mario_.get_rect();
    
    //Finder sets
    std::set<Platform*> vis_platforms = finder_platrform_.query(camrect);
    std::set<Floppy*> vis_floppys = finder_floppy_.query(camrect);
    std::set<Cd*> vis_cds = finder_cd_.query(camrect);
    std::set<Android*> vis_androids = finder_android_.query(camrect);
    std::set<Circuitfloor*> vis_cfloor = finder_cfloor_.query(camrect);
    std::set<Spark*> vis_sparks = finder_sparks_.query(camrect);
    std::set<Bowser*> vis_bowser = finder_bowser_.query(camrect);

    
    update_bowser(window,vis_bowser ,vis_platforms, vis_cfloor, mario_rect);
    mario_.update(window, vis_platforms, vis_cfloor);

    update_floppy(window, vis_floppys);
    update_cds(window, vis_cds);
    update_androids(window, vis_androids, vis_platforms, vis_cfloor);


}

void Game::update_camera(pro2::Window& window) {
    const Pt pos = mario_.pos();
    const Pt cam = window.camera_center();
    std::set<Circuitfloor*> vis_cfloor = finder_cfloor_.query(window.camera_rect());
    
    const int left = cam.x - window.width() / 4;
    const int right = cam.x + window.width() / 4;
    const int top = cam.y - window.height() / 4;
    const int bottom = cam.y + window.height() / 4;
    
    int dx = 0, dy = 0;
    if (pos.x > right) {
        dx = pos.x - right;
    } else if (pos.x < left) {
        dx = pos.x - left;
    }
    if (pos.y < top) {
        dy = pos.y - top;
    } else if (pos.y > bottom) {
        dy = pos.y - bottom;
    }

    std::set<Circuitfloor*>::iterator itcc = vis_cfloor.begin();
    // Cam no sobrepasara la altura de window
    int min_y = (*itcc)->bottom() - window.height() / 2;

    int new_cam_y = cam.y + dy;

    if (new_cam_y > min_y) {
        dy = min_y - cam.y;
    }
    window.move_camera({dx, dy});
    
}

void Game::timer_countdown(pro2::Window& window){
    int fps = window.frame_count();
    if(fps % 48 == 0){
        timer_stack_.pop();
    }
}

/***************************************************
 * UPDATE GENERAL 
 **************************************************/
void Game::update(pro2::Window& window) {
    process_keys(window);   //timer_
    if(state_ != PAUSED and not timer_stack_.empty() != 0){
        timer_countdown(window);
        update_objects(window);
        update_camera(window);
    }
    if(state_ == WINED){
        if(window.was_key_pressed('R')) state_ = RESTART;
    }
    if(state_ == WASTED){
        if(window.was_key_pressed('R')) state_ = RESTART;
    }
    if(mario_.pos().y >= window.height()+ 30) {
        state_ = WASTED;
        mario_.set_y(90);
    }
  
    if(timer_stack_.empty()){
        state_ = WASTED;
        if(window.was_key_pressed('R')) state_ = RESTART;
    }
    
    
}

/***************************************************
 * PAINT GENERAL 
 **************************************************/
void Game::paint(pro2::Window& window) { 
    window.clear(sky_blue);
    if(state_ == WASTED) paint_wasted(window);
    if(state_ == WINED) paint_wined(window);
    if(state_ == PAUSED){
        paint_paused(window);
        paint_all_obj(window);
    }
    else if(state_ == PLAYING){
        paint_all_obj(window);
    }

}

void Game::paint_all_obj(pro2::Window& window){
    pro2::Rect camrect = window.camera_rect();
    std::set<Platform*> vis_platforms = finder_platrform_.query(camrect);
    std::set<Floppy*> vis_floppys = finder_floppy_.query(camrect);
    std::set<Cd*> vis_cds = finder_cd_.query(camrect);
    std::set<Android*> vis_androids_ = finder_android_.query(camrect);
    std::set<Circuitfloor*> vis_cfloor = finder_cfloor_.query(camrect);
    std::set<Spark*> vis_sparks  = finder_sparks_.query(camrect);
    std::set<Bowser*> vis_bowser = finder_bowser_.query(camrect);

    for (Platform* p: vis_platforms) {
        (*p).paint(window);
    }
    

    paint_backround(window);
    paint_text_digits(window);
    
    for(Circuitfloor* c: vis_cfloor){
        (*c).paint_circuit_f(window);
    }
    
    Rect reg ({window.camera_rect()});
    int s = 3;
    paint_frame(window, reg, black, 3);
    
    set<Floppy*>::iterator itf = vis_floppys.begin();
    while(itf != vis_floppys.end()){
        (*itf)->paint_f(window); 
        ++itf;   
    }
    
    set<Cd*>::iterator itc = vis_cds.begin();
    while(itc != vis_cds.end()){
        (*itc)->paint_cd(window);
        ++itc;
    }

    for(Android* a: vis_androids_){
        a->paint(window);
    }
    
    for(Bowser* b: vis_bowser){
        if(b->bowser_state() == ALIVE){
            b->paint(window);
            for(Spark* s : vis_sparks){
                s->paint(window);
            }
        }
    }
    
    mario_.paint(window);
   

}

void Game::paint_text_digits(pro2::Window& window){
    pro2::Pt topright = {window.topleft().x + window.width() - 12, window.topleft().y + 9};
    pro2::Pt topleft = {window.topleft().x + 10, window.topleft().y +9};
    pro2::Pt topleftt = {window.topleft().x + 27, window.topleft().y + 20};
    
    paint_digits(window, topleftt, timer_stack_.size());
    paint_digits(window, topright, counter_);
    paint_letters(window, topleft, "TIME");
    paint_letters(window, {topright.x - 80, topright.y}, "FLOPPYS");

}

void Game::paint_backround(pro2::Window& window){
    srand(time(NULL));
    int xm = window.camera_rect().left;
    pro2::Pt pos {rand() % 420 +xm, rand() % - window.height()/4};
    paint_clouds(window, pos);
    
}