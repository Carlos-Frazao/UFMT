import {
  Body,
  Controller,
  Delete,
  Get,
  Param,
  Patch,
  Post,
  UseGuards,
} from '@nestjs/common';
import { JwtAuthGuard } from '../auth/jwt-auth.guard';
import { CreatePersonagemDto } from './dto/create-personagem.dto';
import { UpdatePersonagemDto } from './dto/update-personagem.dto';
import { PersonagemService } from './personagem.service';

@UseGuards(JwtAuthGuard)
@Controller('personagens')
export class PersonagemController {
  constructor(private readonly personagemService: PersonagemService) {}

  @Post()
  create(@Body() createPersonagemDto: CreatePersonagemDto) {
    return this.personagemService.create(createPersonagemDto);
  }

  @Get()
  findAll() {
    return this.personagemService.findAll();
  }

  @Get(':id')
  findOne(@Param('id') id: string) {
    return this.personagemService.findOne(Number(id));
  }

  @Patch(':id')
  update(
    @Param('id') id: string,
    @Body() updatePersonagemDto: UpdatePersonagemDto,
  ) {
    return this.personagemService.update(Number(id), updatePersonagemDto);
  }

  @Delete(':id')
  remove(@Param('id') id: string) {
    return this.personagemService.remove(Number(id));
  }
}
